#pragma once
#include <string>
#include <array>
#include <nlohmann/json.hpp>

#include "characterClass.h"
#include "characterRace.h"
#include "characterStat.h"

class Character {
private:
    std::string Name;
    CharacterRace characterRace;
    CharacterClass characterClass;
    array<CharacterStat, 6> Stats;
    int level;

public:
    Character();
    Character(std::string name, CharacterRace race, CharacterClass cls, int lvl = 1);
    Character(std::string name, CharacterRace race, CharacterClass cls, array<CharacterStat, 6> stats, int lvl = 1);
    Character(nlohmann::json jsonContent);

    nlohmann::json to_json() const;
    std::string getName() const;
    CharacterRace getRace();
    CharacterClass getClass();
    int getLevel();
};
