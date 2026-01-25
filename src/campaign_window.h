#pragma once
#include "app_window.h"

class CampaignWindow : public AppWindow {
public:
    CampaignWindow();
    ~CampaignWindow();

    void buildUI() override;
    void renderOS() override;
    bool shouldClose() const override;

private:
    GLFWwindow* window = nullptr;
};
