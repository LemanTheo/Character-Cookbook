#include "json_utils.h"
#include <fstream>
#include <nlohmann/json.hpp>

void json_utils::save_character(const Character& c, const std::string& path) {
    std::ofstream file(path);
    file << c.to_json().dump(4);
}

Character json_utils::load_character(const std::string& path) {
    std::ifstream file(path);
    nlohmann::json j;
    file >> j;
    return Character::from_json(j);
}
