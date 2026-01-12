#include "json_utils.h"
#include <fstream>
#include <nlohmann/json.hpp>

#include "character.h"
#include <filesystem>

namespace json_utils {

void save_character(const Character& c, const std::string& folder) {
    std::string filename = folder + "/" + c.name + ".json";

    std::ofstream file(filename);
    if (!file.is_open())
        return;

    file << c.to_json().dump(4);
}


Character load_character(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        return Character{};

    nlohmann::json j;
    file >> j;
    return Character::from_json(j);
}



std::vector<Character> load_all_characters(const std::string& folder) {
    std::vector<Character> result;

    for (const auto& entry : std::filesystem::directory_iterator(folder)) {
        if (!entry.is_regular_file())
            continue;

        std::ifstream file(entry.path());
        if (!file.is_open())
            continue;

        nlohmann::json j;
        file >> j;
        result.push_back(Character::from_json(j));
    }

    return result;
}


}
