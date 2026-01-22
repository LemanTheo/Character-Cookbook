#include "characterStat.h"

CharacterStat::CharacterStat()
{
    statName = STRENGTH;
    statCode = STR;
    initialValue = 10;
}

CharacterStat::CharacterStat(StatCodes code, int val)
{
    statCode = code;
    statName = GetNameFromCode(code);
    initialValue = val;
}

StatNames GetNameFromCode(StatCodes code)
{
    switch(code)
    {
        default:
        case 1:
            return STRENGTH;
        case 2:
            return CONSTITUTION;
        case 3:
            return DEXTERITY;
        case 4:
            return INTELLIGENCE;
        case 5:
            return WISDOM;
        case 6:
            return CHARISMA;
    }
}

void CharacterStat::SetInitialValue(int val)
{ initialValue = val; }

int CharacterStat::GetValue()
{
    int realValue = initialValue;

    // we will include here a list of the different stuff such as class/race bonus, potion effects, debuffs, armors, etc

    return realValue;
}

int CharacterStat::GetModifier()
{
    int modifier = (GetValue() / 2) - 5;

    //Same here, waiting to add more stuff before doing anything
}