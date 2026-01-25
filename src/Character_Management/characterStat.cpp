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

    // we will include here a list of the different stuff such as class/race bonus, potion effects, debuffs, armors, etc

    // cout << GetNameFromCode(statCode) << " |-> " << initialValue << endl;
    return realValue;
}

int CharacterStat::getModifier()
{
    int modifier = (getValue() / 2) - 5;

    //Same here, waiting to add more stuff before doing anything

    return modifier;
}