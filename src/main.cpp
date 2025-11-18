#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

struct Character {
    std::string name;
    std::string race;
    std::string cls; // class
};

std::vector<Character> characters;

void LoadCharacters(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return;

    nlohmann::json j;
    file >> j;
    characters.clear();
    for (auto& item : j) {
        characters.push_back({item["name"], item["race"], item["class"]});
    }
}

void SaveCharacters(const std::string& filename) {
    nlohmann::json j;
    for (auto& c : characters) {
        j.push_back({{"name", c.name}, {"race", c.race}, {"class", c.cls}});
    }
    std::ofstream file(filename);
    file << j.dump(4);
}

int main() {
    // ---- GLFW Setup ----
    if (!glfwInit()) return 1;
    GLFWwindow* window = glfwCreateWindow(800, 600, "DnD Campaign Manager", NULL, NULL);
    if (!window) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Vsync

    // ---- ImGui Setup ----
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    LoadCharacters("characters.json");

    char newName[128] = "";
    char newRace[128] = "";
    char newClass[128] = "";

    bool showCampaignWindow = true;   // <-- NEW

    // ---- Main Loop ----
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ---- Keyboard toggle (TAB) ----
        if (ImGui::IsKeyPressed(ImGuiKey_Tab)) {
            showCampaignWindow = !showCampaignWindow;
        }

        // ---- Always-visible Controls Window ----
        ImGui::Begin("Controls");
        if (ImGui::Button(showCampaignWindow ? "Hide UI" : "Show UI")) {
            showCampaignWindow = !showCampaignWindow;
        }
        ImGui::End();

        // ---- Main Campaign UI ----
        if (showCampaignWindow) {
            ImGui::Begin("Campaign Manager");

            ImGui::Text("Characters in your campaign:");
            for (size_t i = 0; i < characters.size(); ++i) {
                ImGui::BulletText("%s (%s %s)",
                    characters[i].name.c_str(),
                    characters[i].race.c_str(),
                    characters[i].cls.c_str());
            }

            ImGui::Separator();
            ImGui::Text("Add a new character:");
            ImGui::InputText("Name", newName, 128);
            ImGui::InputText("Race", newRace, 128);
            ImGui::InputText("Class", newClass, 128);

            if (ImGui::Button("Add Character")) {
                characters.push_back({newName, newRace, newClass});
                SaveCharacters("characters.json");
                newName[0] = newRace[0] = newClass[0] = '\0';
            }

            ImGui::End();
        }

        // ---- Rendering ----
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw ImGui
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // ---- Cleanup ----
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
