#pragma once
#include <string>
#include "character.h"

namespace json_utils {
    void save_character(const Character& c, const std::string& path);
    Character load_character(const std::string& path);
}
