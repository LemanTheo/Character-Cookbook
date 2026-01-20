#include "character_builder.h"
#include "imgui.h"
#include "json_utils.h"

void CharacterBuilderManager::OpenNewBuilder() {
    CharacterDraft draft;
    draft.id = nextBuilderId++;
    builders.push_back(draft);
}

void CharacterBuilderManager::Render(std::vector<Character>& characters) {
    for (size_t i = 0; i < builders.size(); ) {
        CharacterDraft& draft = builders[i];

        std::string title = "Character Builder##" + std::to_string(draft.id);

        if (ImGui::Begin(title.c_str(), &draft.open)) {

            ImGui::InputText("Name", draft.name, 128);
            ImGui::InputText("Race", draft.race, 128);
            ImGui::InputText("Class", draft.cls, 128);

            ImGui::Separator();

            if (ImGui::Button("Create")) {
                Character c(draft.name, CharacterRace(), CharacterClass(), 1);

                characters.push_back(c);
                string folder = "../data/characters";
                json_utils::save_character(c, folder);
                draft.open = false;
            }

            ImGui::SameLine();
            if (ImGui::Button("Discard")) {
                draft.open = false;
            }
        }
        ImGui::End();

        if (!draft.open) {
            builders.erase(builders.begin() + i);
        } else {
            ++i;
        }
    }
}

