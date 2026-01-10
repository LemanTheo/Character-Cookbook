#pragma once
#include <string>
#include "character.h"
#include <vector>

namespace json_utils {
    void save_character(const Character& c, const std::string& path);
    std::vector<Character> load_all_characters(const std::string& folder);
    Character load_character(const std::string& path);
}
