#pragma once
#include <vector>
#include <string>
#include "Character_Management/character.h"

// One in-progress character
struct CharacterDraft {
    char name[128] = "";
    char race[128] = "";
    char cls[128]  = "";

    bool open = true;
    int id = 0;
};


// Manager for all builder windows
class CharacterBuilderManager {
public:
    void OpenNewBuilder();
    void Render(std::vector<Character>& characters);

private:
    std::vector<CharacterDraft> builders;
    int nextBuilderId = 1;
};
