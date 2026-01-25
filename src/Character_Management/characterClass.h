#pragma once
#include <String>
#include <nlohmann/json.hpp>

using namespace std;

class CharacterClass {
    private:
        string className;
    public:
        CharacterClass();
        string getName() const;
};