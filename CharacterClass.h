#pragma once

#include <iostream>
#include <string>

using std::string;

struct CharacterClass {
    string mName;
    int defaultHealth;

    string getName();



    // Constructor
    CharacterClass(const string& className, int health);
};


