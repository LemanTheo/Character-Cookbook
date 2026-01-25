#include "character.h"

using namespace std;

Character::Character()
{
    Name = "Unnamed Character";
    characterClass = CharacterClass();
    characterRace = CharacterRace();
    level = 1;
    STRStat = CharacterStat(); 
    CONStat = CharacterStat();
    DEXStat = CharacterStat();
    INTStat = CharacterStat();
    WISStat = CharacterStat();
    CHAStat = CharacterStat();
}

Character::Character(std::string name, CharacterRace race, CharacterClass cls, array<CharacterStat, 6> stats, int lvl)
{
    Name = name;
    characterClass = cls;
    characterRace = race;
    level = lvl;
    STRStat = stats.at(0);
    CONStat = stats.at(1);
    DEXStat = stats.at(2);
    INTStat = stats.at(3);
    WISStat = stats.at(4);
    CHAStat = stats.at(5);
}

Character::Character(string name, CharacterRace race, CharacterClass cls, int lvl)
{
    Name = name;
    characterClass = cls;
    characterRace = race;
    level = lvl;
    STRStat = CharacterStat(); 
    CONStat = CharacterStat();
    DEXStat = CharacterStat();
    INTStat = CharacterStat();
    WISStat = CharacterStat();
    CHAStat = CharacterStat();
}
Character::Character(nlohmann::json jsonContent)
{
    Name = jsonContent.value("name", "Unnamed Character");
    characterClass = CharacterClass();
    characterRace = CharacterRace();
    // characterRace = jsonContent.value("race", "Human");
    // characterClass = jsonContent.value("class", "Fighter");
    level = jsonContent.value("level", 1);

    // We might need to work on that later...
    // Stats = new CharacterStat[6];
    STRStat = CharacterStat(); 
    CONStat = CharacterStat();
    DEXStat = CharacterStat();
    INTStat = CharacterStat();
    WISStat = CharacterStat();
    CHAStat = CharacterStat();
}

nlohmann::json Character::to_json() const {
    return {
        {"name", Name},
        {"race", characterRace.getName()},
        {"class", characterClass.getName()},
        {"level", level},
        // {"stats", Stats}
    };
}

string Character::getName() const
{ return Name; }

CharacterRace Character::getRace()
{ return characterRace; }

CharacterClass Character::getClass()
{ return characterClass; }

int Character::getLevel()
{ return level; }

int Character::setStat(StatCodes code, int val)
{
    switch(code)
    {
        case StatCodes::STR:
            std::cout << "changing STR: " << val << endl;
            STRStat = CharacterStat(val); 
            std::cout << CONStat.getValue() << endl;

            return 0;
        case StatCodes::CON:
            CONStat = CharacterStat(val);
            return 0;
        case StatCodes::DEX:
            DEXStat = CharacterStat(val);
            return 0;
        case StatCodes::INT:
            INTStat = CharacterStat(val);            return 0;
        case StatCodes::WIS:
            WISStat = CharacterStat(val);
            return 0;
        case StatCodes::CHA:
            CHAStat = CharacterStat(val);
            return 0;
        default:
            return 1;
    }
}

int Character::setStat(StatCodes code, CharacterStat stat)
{
    switch(code)
    {
        case StatCodes::STR:
            STRStat = stat;
            return 0;
        case StatCodes::CON:
            CONStat = stat;
            return 0;
        case StatCodes::DEX:
            DEXStat = stat;
            return 0;
        case StatCodes::INT:
            INTStat = stat;
            return 0;
        case StatCodes::WIS:
            WISStat = stat;
            return 0;
        case StatCodes::CHA:
            CHAStat = stat;
            return 0;
        default:
            return 1;
    }
}

void Character::setStats(array<CharacterStat, 6> stats)
{ 
    STRStat = stats.at(0);
    CONStat = stats.at(1);
    DEXStat = stats.at(2);
    INTStat = stats.at(3);
    WISStat = stats.at(4);
    CHAStat = stats.at(5);
}


array<CharacterStat, 6> Character::getStats()
{
    cout << STRStat.getValue() << endl;
    array<CharacterStat, 6> stats = {STRStat, CONStat, DEXStat, INTStat, WISStat, CHAStat};
    return stats;
}