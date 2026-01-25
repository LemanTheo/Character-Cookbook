#include "gl_buttons.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include "imgui.h"

void DrawGLButton(const GLButton& btn) {
    int display_w, display_h;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &display_w, &display_h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, display_w, display_h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    bool mouseDown =
        glfwGetMouseButton(glfwGetCurrentContext(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    if (btn.hovered && mouseDown)
        glColor3f(btn.clickColor[0], btn.clickColor[1], btn.clickColor[2]);
    else if (btn.hovered)
        glColor3f(btn.hoverColor[0], btn.hoverColor[1], btn.hoverColor[2]);
    else
        glColor3f(btn.baseColor[0], btn.baseColor[1], btn.baseColor[2]);

    glBegin(GL_QUADS);
    glVertex2f(btn.x, btn.y);
    glVertex2f(btn.x + btn.w, btn.y);
    glVertex2f(btn.x + btn.w, btn.y + btn.h);
    glVertex2f(btn.x, btn.y + btn.h);
    glEnd();

    // ---- TEXT (ImGui) ----
    ImDrawList* draw_list = ImGui::GetForegroundDrawList();
    ImVec2 textSize = ImGui::CalcTextSize(btn.label);
    ImVec2 textPos(
        btn.x + (btn.w - textSize.x) * 0.5f,
        btn.y + (btn.h - textSize.y) * 0.5f
    );

    draw_list->AddText(textPos, IM_COL32(255, 255, 255, 255), btn.label);
}

bool HandleGLButton(GLButton& btn) {
    double mx, my;
    GLFWwindow* window = glfwGetCurrentContext();
    glfwGetCursorPos(window, &mx, &my);

    btn.hovered =
        mx >= btn.x && mx <= btn.x + btn.w &&
        my >= btn.y && my <= btn.y + btn.h;

    bool mouseDown =
        glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    bool clicked = btn.hovered && mouseDown && !btn.prevMouseDown;
    btn.prevMouseDown = mouseDown;

    return clicked;
}
