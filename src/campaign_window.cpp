#include "campaign_window.h"

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"

#include <GL/gl.h>

CampaignWindow::CampaignWindow() {
    // Share OpenGL context with current one (Root)
    window = glfwCreateWindow(
        700,
        500,
        "Campaign Manager",
        nullptr,
        glfwGetCurrentContext()
    );
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

CampaignWindow::~CampaignWindow() {
    glfwDestroyWindow(window);
}

bool CampaignWindow::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void CampaignWindow::buildUI() {
    ImGui::Begin("Campaign Manager");
    ImGui::Text("This is a long-lived OS window.");
    ImGui::Text("Maps, encounters, NPCs will live here.");
    ImGui::End();
}

void CampaignWindow::renderOS() {
    glfwMakeContextCurrent(window);

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glClearColor(0.15f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}
