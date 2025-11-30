#include "gui.h"
#include "json_utils.h"
#include <imgui.h>

void render_character_editor(Character& c) {
    ImGui::Begin("Character Editor");

    char name_buf[64]; strncpy(name_buf, c.name.c_str(), sizeof(name_buf));
    char race_buf[64]; strncpy(race_buf, c.race.c_str(), sizeof(race_buf));
    char class_buf[64]; strncpy(class_buf, c.cls.c_str(), sizeof(class_buf));

    ImGui::InputText("Name", name_buf, IM_ARRAYSIZE(name_buf));
    ImGui::InputText("Race", race_buf, IM_ARRAYSIZE(race_buf));
    ImGui::InputText("Class", class_buf, IM_ARRAYSIZE(class_buf));
    ImGui::SliderInt("Level", &c.level, 1, 20);

    c.name = name_buf;
    c.race = race_buf;
    c.cls = class_buf;

    if (ImGui::Button("Save")) {
        json_utils::save_character(c, "data/characters/" + c.name + ".json");
    }

    ImGui::End();
}
