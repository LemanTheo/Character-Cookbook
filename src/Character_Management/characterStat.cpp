#include "characterStat.h"

using namespace std;

CharacterStat::CharacterStat()
{
    initialValue = 10;
}

CharacterStat::CharacterStat(int val)
{
    initialValue = val;
}

void CharacterStat::setInitialValue(int val)
{ initialValue = val; }

int CharacterStat::getValue()
{
    int realValue = initialValue;

    for(int i = 0; i < valueBuffs.size(); i++)
        realValue += valueBuffs[i];

    return realValue;
}

int CharacterStat::getModifier()
{
    int modifier = (getValue() / 2) - 5;

    for(int i = 0; i < modifierBuffs.size(); i++)
        modifier += modifierBuffs[i];

    return modifier;
}

// Does not work yet, need to work some kinks
void CharacterStat::addValueBuff(int buff)
{
    cout << valueBuffs.size() << " ";
    valueBuffs.push_back(buff);
    cout << valueBuffs.size() << " ";
    cout << endl;
}

void CharacterStat::addModBuff(int buff)
{ modifierBuffs.push_back(buff); }