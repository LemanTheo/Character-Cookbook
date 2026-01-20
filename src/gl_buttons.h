#pragma once
#include <GLFW/glfw3.h>

struct GLButton {
    float x, y, w, h;
    bool hovered = false;
    bool prevMouseDown = false; // for edge detection
};

// Draw the button
void DrawGLButton(const GLButton& btn);

// Returns true **once** when the button is clicked
bool HandleGLButton(GLButton& btn);
