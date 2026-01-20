#include "character.h"

using namespace std;

Character::Character()
{
    Name = "Unnamed Character";
    characterClass = CharacterClass();
    characterRace = CharacterRace();
    level = 1;
}

Character::Character(string name, CharacterRace race, CharacterClass cls, int lvl)
{
    Name = name;
    characterClass = cls;
    characterRace = race;
    level = lvl;
}

Character::Character(nlohmann::json jsonContent)
{
    Name = jsonContent.value("name", "Unnamed Character");
    characterClass = CharacterClass();
    characterRace = CharacterRace();
    // characterRace = jsonContent.value("race", "Human");
    // characterClass = jsonContent.value("class", "Fighter");
    level = jsonContent.value("level", 1);
}

nlohmann::json Character::to_json() const {
    return {
        {"name", Name},
        {"race", characterRace.getName()},
        {"class", characterClass.getName()},
        {"level", level}
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