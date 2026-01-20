#include "gl_buttons.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h> // for OpenGL functions

void DrawGLButton(const GLButton& btn) {
    int display_w, display_h;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &display_w, &display_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, display_w, display_h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Hover color
    glColor3f(btn.hovered ? 0.85f : 0.65f, btn.hovered ? 0.30f : 0.25f, 0.25f);

    glBegin(GL_QUADS);
    glVertex2f(btn.x, btn.y);
    glVertex2f(btn.x + btn.w, btn.y);
    glVertex2f(btn.x + btn.w, btn.y + btn.h);
    glVertex2f(btn.x, btn.y + btn.h);
    glEnd();
}

bool HandleGLButton(GLButton& btn) {
    // Get mouse position
    double mx, my;
    GLFWwindow* window = glfwGetCurrentContext();
    glfwGetCursorPos(window, &mx, &my);

    // Check hover
    btn.hovered =
        mx >= btn.x &&
        mx <= btn.x + btn.w &&
        my >= btn.y &&
        my <= btn.y + btn.h;

    // Mouse button
    bool mouseDown = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    // Detect click (press edge)
    bool clicked = btn.hovered && mouseDown && !btn.prevMouseDown;

    // Update state
    btn.prevMouseDown = mouseDown;

    return clicked;
}
