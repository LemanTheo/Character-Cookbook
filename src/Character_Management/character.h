#pragma once
#include <string>
#include <nlohmann/json.hpp>

#include "characterClass.h"
#include "characterRace.h"

// using namespace std;

// class CharacterRace;
// class CharacterClass;

class Character {
private:
    std::string Name;
    CharacterRace characterRace;
    CharacterClass characterClass;
    int level;


public:
    Character();
    Character(std::string name, CharacterRace race, CharacterClass cls, int lvl = 1);
    Character(nlohmann::json jsonContent);

    nlohmann::json to_json() const;
    std::string getName() const;
    CharacterRace getRace();
    CharacterClass getClass();
    int getLevel();
};
