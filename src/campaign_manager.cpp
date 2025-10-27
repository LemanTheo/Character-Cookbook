#include "campaign_manager.h"
#include "json_utils.h"
#include <filesystem>
#include <imgui.h>

namespace fs = std::filesystem;

void CampaignManager::load_characters(const std::string& folderPath) {
    characters.clear();
    for (auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.path().extension() == ".json") {
            try {
                Character c = json_utils::load_character(entry.path().string());
                characters.push_back(c);
            } catch (...) {
                // Ignore corrupted files for now
            }
        }
    }
}

void CampaignManager::render() {
    ImGui::Begin("Campaign Manager");

    if (ImGui::Button("Reload Characters")) {
        load_characters("data/characters");
    }
    ImGui::SameLine();
    if (ImGui::Button("New Character")) {
        characters.push_back(Character("NewHero", "Human", "Fighter", 1));
        selectedIndex = static_cast<int>(characters.size()) - 1;
    }

    ImGui::Separator();

    if (characters.empty()) {
        ImGui::Text("No characters found. Click 'Reload' or 'New Character'.");
    } else {
        for (int i = 0; i < static_cast<int>(characters.size()); ++i) {
            const bool isSelected = (i == selectedIndex);
            if (ImGui::Selectable(characters[i].name.c_str(), isSelected)) {
                selectedIndex = i;
            }
        }
    }

    ImGui::End();
}
