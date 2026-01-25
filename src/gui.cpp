#include "gui.h"
#include "json_utils.h"
#include <imgui.h>

void render_character_editor(Character& c) {
    ImGui::Begin("Character Editor");

    char name_buf[64]; strncpy(name_buf, c.getName().c_str(), sizeof(name_buf));
    char race_buf[64]; strncpy(race_buf, c.getRace().getName().c_str(), sizeof(race_buf));
    char class_buf[64]; strncpy(class_buf, c.getClass().getName().c_str(), sizeof(class_buf));
    int level_buf[64];

    ImGui::InputText("Name", name_buf, IM_ARRAYSIZE(name_buf));
    ImGui::InputText("Race", race_buf, IM_ARRAYSIZE(race_buf));
    ImGui::InputText("Class", class_buf, IM_ARRAYSIZE(class_buf));
    ImGui::SliderInt("Level", level_buf, 1, 20);

    c = Character(name_buf, CharacterRace(), CharacterClass(), level_buf[0]);

    if (ImGui::Button("Save")) {
        string path = "../data/characters/"; 
        json_utils::save_character(c, path.append(c.getName().append(".json")));
        //SaveCharacters("data/characters/" + c.name + ".json", characters);
    }

    ImGui::End();
}
