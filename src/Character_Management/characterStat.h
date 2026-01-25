#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum StatCodes {STR = 0, CON = 1, DEX = 2, INT = 3, WIS = 4, CHA = 5};

class CharacterStat
{
    private:
        int initialValue;
        vector<int> valueBuffs;
        vector<int> modifierBuffs;

    public:
        CharacterStat();
        CharacterStat(int val);

        void setInitialValue(int val);
        int getValue();
        int getModifier();
        void addValueBuff(int buff);
        void addModBuff(int buff);
};