#pragma once
#include <vector>
#include <string>
#include "character.h"

class CampaignManager {
public:
    std::vector<Character> characters;
    int selectedIndex = -1;

    void load_characters(const std::string& folderPath);
    void render();
};
