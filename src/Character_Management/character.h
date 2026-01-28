#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>
#include <array>

#include "characterClass.h"
#include "characterRace.h"
#include "characterStat.h"
#include "characterSkill.h"

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
    
    CharacterSkill Acrobatics;
    CharacterSkill AnimalHandling;
    CharacterSkill Arcana;
    CharacterSkill Athletics;
    CharacterSkill Deception;
    CharacterSkill HistorySkill;
    CharacterSkill Insight;
    CharacterSkill Intimidation;
    CharacterSkill Investigation;
    CharacterSkill Medicine;
    CharacterSkill Nature;
    CharacterSkill Perception;
    CharacterSkill Performance;
    CharacterSkill Persuasion;
    CharacterSkill Religion;
    CharacterSkill SleightOfHand;
    CharacterSkill Stealth;
    CharacterSkill Survival;

    int level;

public:
    Character();
    Character(std::string name, CharacterRace race, CharacterClass cls, int lvl = 1);
    Character(std::string name, CharacterRace race, CharacterClass cls, array<CharacterStat, 6> stats, int lvl = 1);
    Character(nlohmann::json jsonContent);

    nlohmann::json to_json() const;
    std::string getName() const;
    CharacterRace getRace() const;
    CharacterClass getClass() const;
    int getLevel() const;

    CharacterStat getStat(StatCodes code);
    CharacterSkill getSkill(SkillCodes code);

    int setStat(StatCodes code, int val);
    int setStat(StatCodes code, CharacterStat stat);
    void setStats(array<CharacterStat, 6> stats);

};
