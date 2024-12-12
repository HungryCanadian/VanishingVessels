#include "Race.h"

// Constructor implementation
Race::Race(const std::string raceName, int strBonus, int dexBonus, int conBonus, int intlBonus, int wisBonus, int chaBonus)
    : mName(raceName), abilityIncrease(strBonus, dexBonus, conBonus, intlBonus, wisBonus, chaBonus) {
}
