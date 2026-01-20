#pragma once
#include <string>
#include "Character_Management/character.h"
#include <vector>

//Apparently, this file forgot the Character class exists...
class Character;

namespace json_utils {
    void save_character(const Character& c, const std::string& path);
    std::vector<Character> load_all_characters(const std::string& folder);
    Character load_character(const std::string& path);
}
