#pragma once
#include "app_window.h"

#include <memory>
#include <vector>

class CampaignWindow;

class RootWindow : public AppWindow {
public:
    RootWindow();
    ~RootWindow();

    void buildUI() override;
    void renderOS() override;
    bool shouldClose() const override;

    GLFWwindow* getGLFWWindow() const { return window; }

private:
    GLFWwindow* window = nullptr;
    std::vector<std::unique_ptr<AppWindow>> children;
};
