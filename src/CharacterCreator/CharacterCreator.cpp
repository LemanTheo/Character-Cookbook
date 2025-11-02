// Created by Pomm2Terr the 01/11/2025. Last edited by Pomm2Terr the 01/11/2025.
// CharacterCreator.cpp will be in charge of creating and editing a character sheet in JSON format.
// The data management needed for the content of that character sheet will be done in other programs (which will most probably be called in this code).

#include "CharacterCreator.h"
using namespace std;

//TODO: change the variable type to JSON:                      Here \/ 
string CharacterCreator(string Name, string File, string argJSON, string ImageFile = NULL, string TokenFile = NULL)
{
    //Data fetching

    //File Creation
    ofstream CharacterSheet(File);

    CharacterSheet.close();
    return "OK"
}