#include "CharacterSkill.h"

using namespace std;

CharacterSkill::CharacterSkill()
{
    CharacterStat();
    BaseStat = NULL;
    modifierBuffs = {};
}

CharacterSkill::CharacterSkill(CharacterStat *baseStat)
{
    CharacterStat();
    *BaseStat = *baseStat;
    modifierBuffs = {};
}

int CharacterSkill::getModifier()
{
    int modifier = BaseStat->getModifier();

    for(int i = 0; i < modifierBuffs.size(); i++)
        modifier += modifierBuffs[i];

    return modifier;
}

void CharacterSkill::addValueBuff(int buff)
{ modifierBuffs.push_back(buff); }