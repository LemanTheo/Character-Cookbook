#include "root_window.h"
#include "campaign_window.h"

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"

#include <GL/gl.h>

RootWindow::RootWindow() {
    window = glfwCreateWindow(800, 600, "DnD Manager — Root", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

RootWindow::~RootWindow() {
    children.clear(); // destroy children first
    glfwDestroyWindow(window);
}

bool RootWindow::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void RootWindow::buildUI() {
    ImGui::Begin("Root");
    if (ImGui::Button("Open Campaign Manager")) {
        children.push_back(std::make_unique<CampaignWindow>());
    }
    ImGui::End();

    for (auto& child : children) {
        child->buildUI();
    }
}

void RootWindow::renderOS() {
    // ---- Render root window ----
    glfwMakeContextCurrent(window);

    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);

    // ---- Render child windows ----
    for (auto it = children.begin(); it != children.end();) {
        if ((*it)->shouldClose()) {
            it = children.erase(it);
        } else {
            (*it)->renderOS();
            ++it;
        }
    }
}
