#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <array>

#include "characterClass.h"
#include "characterRace.h"
#include "characterStat.h"

class Character {
private:
    std::string Name;
    CharacterRace characterRace;
    CharacterClass characterClass;
    CharacterStat STRStat;
    CharacterStat CONStat;
    CharacterStat DEXStat;
    CharacterStat INTStat;
    CharacterStat WISStat;
    CharacterStat CHAStat;
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

    int setStat(StatCodes code, int val);
    int setStat(StatCodes code, CharacterStat stat);
    void setStats(array<CharacterStat, 6> stats);
    array<CharacterStat, 6> getStats();
};
