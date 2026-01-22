#include "character.h"

using namespace std;

Character::Character()
{
    Name = "Unnamed Character";
    characterClass = CharacterClass();
    characterRace = CharacterRace();
    level = 1;
    Stats = {
        CharacterStat(StatCodes::STR), 
        CharacterStat(StatCodes::CON),
        CharacterStat(StatCodes::DEX),
        CharacterStat(StatCodes::INT),
        CharacterStat(StatCodes::WIS),
        CharacterStat(StatCodes::CHA)
    };
}

Character::Character(string name, CharacterRace race, CharacterClass cls, array<CharacterStat, 6> stats, int lvl)
{
    Name = name;
    characterClass = cls;
    characterRace = race;
    level = lvl;
    Stats = stats;
}

Character::Character(string name, CharacterRace race, CharacterClass cls, int lvl)
{
    Name = name;
    characterClass = cls;
    characterRace = race;
    level = lvl;
    Stats = {
        CharacterStat(StatCodes::STR), 
        CharacterStat(StatCodes::CON),
        CharacterStat(StatCodes::DEX),
        CharacterStat(StatCodes::INT),
        CharacterStat(StatCodes::WIS),
        CharacterStat(StatCodes::CHA)
    };
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
    Stats = {
        CharacterStat(StatCodes::STR), 
        CharacterStat(StatCodes::CON),
        CharacterStat(StatCodes::DEX),
        CharacterStat(StatCodes::INT),
        CharacterStat(StatCodes::WIS),
        CharacterStat(StatCodes::CHA)
    };
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