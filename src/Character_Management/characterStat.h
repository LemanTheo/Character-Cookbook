#pragma once

#include <iostream>
#include <string>

using namespace std;

enum StatCodes {STR = 0, CON = 1, DEX = 2, INT = 3, WIS = 4, CHA = 5};

class CharacterStat
{
    private:
        int initialValue;

    public:
        CharacterStat();
        CharacterStat(int val);

        void setInitialValue(int val);
        int getValue();
        int getModifier();
};