#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

// ===================================================
//                --- STRUCTS ---
// ===================================================
struct Character {
    std::string name;
    std::string race;
    std::string cls; // class
};

std::vector<Character> characters;

struct GLButton {
    float x, y, w, h;
    bool hovered = false;
    bool pressed = false;
};

// ===================================================
//              --- JSON LOAD/SAVE ---
// ===================================================
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
//    for (const Character& c : characters) {
//        j.push_back({ {"name", c.name}, {"race", c.race}, {"class", c.cls} });
//    }
    for (size_t i = 0; i < characters.size(); ++i) {
        Character c = characters[i];
        j.push_back({ {"name", c.name}, {"race", c.race}, {"class", c.cls} });
        }  
    std::ofstream file(filename);
    file << j.dump(4);
}

// ===================================================
//             --- OPENGL BUTTON RENDER ---
// ===================================================
void DrawGLButton(const GLButton& btn) {
    int display_w, display_h;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &display_w, &display_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, display_w, display_h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Hover color
    if (btn.hovered)
        glColor3f(0.85f, 0.30f, 0.30f);
    else
        glColor3f(0.65f, 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(btn.x, btn.y);
    glVertex2f(btn.x + btn.w, btn.y);
    glVertex2f(btn.x + btn.w, btn.y + btn.h);
    glVertex2f(btn.x, btn.y + btn.h);
    glEnd();
}

// ===================================================
//                    --- MAIN ---
// ===================================================
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

    bool showCampaignWindow = true;

    // ---- Background OpenGL Button ----
    GLButton backgroundButton = { 20, 20, 150, 40 };

    // ---- Main Loop ----
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // ====== NEW: BACKGROUND BUTTON INTERACTION ======
        double mx, my;
        glfwGetCursorPos(window, &mx, &my);

        backgroundButton.hovered =
            mx >= backgroundButton.x &&
            mx <= backgroundButton.x + backgroundButton.w &&
            my >= backgroundButton.y &&
            my <= backgroundButton.y + backgroundButton.h;

        if (backgroundButton.hovered &&
            glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        {
            backgroundButton.pressed = true;
        }

        // =================================================
        //                IMGUI NEW FRAME
        // =================================================
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Keyboard toggle
        if (ImGui::IsKeyPressed(ImGuiKey_Tab)) {
            showCampaignWindow = !showCampaignWindow;
        }

        // Always-visible controls window
        ImGui::Begin("Controls");
        if (ImGui::Button(showCampaignWindow ? "Hide UI" : "Show UI"))
            showCampaignWindow = !showCampaignWindow;
        ImGui::End();

        // Campaign window
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

        // =================================================
        //                --- RENDERING ---
        // =================================================
        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        // Background clear color
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // ====== DRAW BACKGROUND BUTTON ======
        DrawGLButton(backgroundButton);

        // Handle button click AFTER drawing
        if (backgroundButton.pressed) {
            std::cout << "Background Button Clicked!" << std::endl;
            backgroundButton.pressed = false;
        }

        // ====== IMGUI RENDER ======
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