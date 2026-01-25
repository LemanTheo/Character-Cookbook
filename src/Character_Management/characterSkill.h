# pragma once

#include "characterStat.h"

#include <iostream>

enum SkillCodes { ACROBATICS, ANIMAL_HANDLING, ARCANA, ATHLETICS, DECEPTION, HISTORY, INSIGHT, INTIMIDATION, INVESTIGATION, MEDICINE, NATURE, PERCEPTION, PERFORMANCE, PERSUASION, RELIGION, SLEIGHT_OF_HAND, STEALTH, SURVIVAL };

class CharacterSkill: public CharacterStat
{
    private:
        CharacterStat* BaseStat;
        vector<int> modifierBuffs;
    public:
        using CharacterStat::getModifier;
        CharacterSkill();
        CharacterSkill(CharacterStat *baseStat);
        int getModifier();
        void addValueBuff(int buff);
};