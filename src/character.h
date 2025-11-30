#pragma once
#include <string>
#include <nlohmann/json.hpp>

class Character {
public:
    std::string name;
    std::string race;
    std::string cls;
    int level = 1;

    Character() = default;
    Character(std::string name, std::string race, std::string cls, int level)
        : name(std::move(name)), race(std::move(race)), cls(std::move(cls)), level(level) {}

    nlohmann::json to_json() const;
    static Character from_json(const nlohmann::json& j);
};
