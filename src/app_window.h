#pragma once
#include <GLFW/glfw3.h>

class AppWindow {
public:
    virtual ~AppWindow() = default;

    // Build ImGui widgets (ImGui::Begin, Button, Text, etc.)
    virtual void buildUI() = 0;

    // Render to the OS window (OpenGL + swap buffers)
    virtual void renderOS() = 0;

    virtual bool shouldClose() const = 0;
};
