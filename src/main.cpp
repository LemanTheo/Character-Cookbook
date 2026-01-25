#include <GLFW/glfw3.h>

#include "root_window.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

int main() {
    if (!glfwInit())
        return 1;

    // Create root window first
    RootWindow root;

    // ---- Global ImGui initialization (ONCE) ----
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(root.getGLFWWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // ---- Main loop ----
    while (!root.shouldClose()) {
        glfwPollEvents();

        // One ImGui frame per application frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Build all UI
        root.buildUI();

        // Finalize ImGui frame
        ImGui::Render();

        // Render all OS windows
        root.renderOS();
    }

    // ---- Shutdown ----
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}
