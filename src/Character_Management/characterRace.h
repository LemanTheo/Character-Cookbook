#pragma once
#include <String>
#include <nlohmann/json.hpp>

using namespace std;

class CharacterRace {
    private:
        string raceName;
    public:
        CharacterRace();
        string getName() const;
};