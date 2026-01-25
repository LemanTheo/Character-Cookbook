#pragma once
#include <GLFW/glfw3.h>

struct GLButton {
    float x, y, w, h;
    const char* label = "";
    bool hovered = false;
    bool prevMouseDown = false;

    float baseColor[3]  = {0.2f, 0.5f, 0.8f};
    float hoverColor[3] = {0.3f, 0.6f, 1.0f};
    float clickColor[3] = {0.1f, 0.4f, 0.7f};
};

void DrawGLButton(const GLButton& btn);
bool HandleGLButton(GLButton& btn);
