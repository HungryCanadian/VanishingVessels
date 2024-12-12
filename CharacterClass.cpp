#include "CharacterClass.h"

// Constructor implementation
CharacterClass::CharacterClass(const std::string& className, int health)
    : mName(className), defaultHealth(health) {
}

string CharacterClass::getName() {
    return mName;
}