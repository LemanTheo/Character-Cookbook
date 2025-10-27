#include "character.h"

nlohmann::json Character::to_json() const {
    return {
        {"name", name},
        {"race", race},
        {"class", cls},
        {"level", level}
    };
}

Character Character::from_json(const nlohmann::json& j) {
    Character c;
    c.name = j.value("name", "Unnamed");
    c.race = j.value("race", "Human");
    c.cls = j.value("class", "Fighter");
    c.level = j.value("level", 1);
    return c;
}
