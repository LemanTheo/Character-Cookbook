#pragma once

enum StatNames {STRENGTH = 1, CONSTITUTION = 2, DEXTERITY = 3, INTELLIGENCE = 4, WISDOM = 5, CHARISMA = 6};
enum StatCodes {STR = 1, CON = 2, DEX = 3, INT = 4, WIS = 5, CHA = 6};
StatNames GetNameFromCode(StatCodes code);

class CharacterStat
{
    public:
    private:
        StatNames statName;
        StatCodes statCode;
        int initialValue;

    public:
        CharacterStat();
        CharacterStat(StatCodes code, int val = 10);

        void SetInitialValue(int val);
        int GetValue();
        int GetModifier();
};