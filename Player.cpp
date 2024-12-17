#include "Player.h"
#include <vector>
#include "RaceData.h"

// Static instance initialization
Player* Player::sInstance = nullptr;

// Singleton instance method
Player* Player::Instance(std::string name, std::string characterRace,
    std::string characterClass, int level,
    int experience, int expToLevel, int gold) {
    if (!sInstance) {  // Only create a new instance if it doesn't exist
        sInstance = new Player(name, characterRace, characterClass, level,
            experience, expToLevel, gold);
    }
    return sInstance;
}

// Player constructor
Player::Player(std::string name, std::string characterRace,
    std::string characterClass, int level, int experience,
    int expToLevel, int gold)
    : mName(name), mRace(characterRace), mCharClass(characterClass),
    mLevel(level), mExperience(experience), mExpToLevel(expToLevel),
    mGold(gold), mHealth(100), mMaxHealth(100), mDamage(10),
    mSpecialAttackTotal(3), mUltimateAttackTotal(1) {
    // Constructor logic (e.g., apply bonuses, calculate health)
    std::cout << "Player created with race: " << mRace
        << ", class: " << mCharClass << std::endl;

    srand(static_cast<unsigned int>(time(0)));
}

// Getter and Setter for Race
std::string Player::GetRace() {
    return mRace;
}

void Player::SetRace(std::string race) {
    mRace = race;
    
}

// Getter and Setter for Class
std::string Player::GetClass() {
    return mCharClass;
}

void Player::SetClass(std::string charClass) {
    mCharClass = charClass;
    // Apply class-specific logic if needed
}

// Release method for Singleton cleanup
void Player::Release() {
    delete sInstance;
    sInstance = nullptr;
}



void Player::SetAttributes() {

}

int Player::GetStrength() {
    return mStrength;
}
int Player::GetDexterity() {
    return mDexterity;
}
int Player::GetConstitution() {
    return mConstitution;
}
int Player::GetIntelligence() {
    return mIntellect;
}
int Player::GetWisdom() {
    return mWisdom;
}
int Player::GetCharisma() {
    return mCharisma;
}
int Player::GetStrengthBonus() {
    return mStrengthBonus;
}
int Player::GetDexterityBonus() {
    return mDexterityBonus;
}
int Player::GetConstitutionBonus() {
    return mConstitutionBonus;
}
int Player::GetIntelligenceBonus() {
    return mIntellectBonus;
}
int Player::GetWisdomBonus() {
    return mWisdomBonus;
}
int Player::GetCharismaBonus() {
    return mCharismaBonus;
}

void Player::AddDamageReduction(int amount) {
    totalDamageReduction += amount;
}

void Player::RemoveDamageReduction(int amount) {
    totalDamageReduction -= amount;
    if (totalDamageReduction < 0) {
        totalDamageReduction = 0; // make sure you can't take extra damage anymore
    }
}


void Player::RaceBonuses() {
    if (mRace == "Human") {
        mConstitutionRaceBonus = 1;
        mWisdomRaceBonus = 2;
    }
    else if (mRace == "Elf") {
        mDexterityRaceBonus = 2;
    }
    else if (mRace == "Dwarf") {
        mConstitutionRaceBonus = 2;
    }
    else if (mRace == "Halfling") {
        mDexterityRaceBonus = 2;
    }
    else if (mRace == "Gnome") {
        mIntellectRaceBonus = 2;
    }
    else if (mRace == "Tiefling") {
        mCharismaRaceBonus = 2;
        mIntellectRaceBonus = 1;
    }
}

void Player::CalculateBonuses() {
    mStrength = mStrength + mStrengthRaceBonus;
    mDexterity = mDexterity + mDexterityRaceBonus;
    mConstitution = mConstitution + mConstitutionRaceBonus;
    mIntellect = mIntellect + mIntellectRaceBonus;
    mWisdom = mWisdom + mWisdomRaceBonus;
    mCharisma = mCharisma + mCharismaRaceBonus;

    mStrengthBonus = (mStrength - 10) / 2;
    mDexterityBonus = (mDexterity - 10) / 2;
    mConstitutionBonus = (mConstitution - 10) / 2;
    mIntellectBonus = (mIntellect - 10) / 2;
    mWisdomBonus = (mWisdom - 10) / 2;
    mCharismaBonus = (mCharisma - 10) / 2;
}

void Player::GenerateRandomStats() {
    srand(static_cast<unsigned int>(time(0)));
    mStrength = std::rand() % 11 + 8;  // Strength
    mDexterity = std::rand() % 11 + 8;  // Dexterity
    mConstitution = std::rand() % 11 + 8;  // Constitution
    mIntellect = std::rand() % 11 + 8;  // Intelligence
    mWisdom = std::rand() % 11 + 8;  // Wisdom
    mCharisma = std::rand() % 11 + 8;  // Charisma
}

void Player::calculateHealth() {
    mMaxHealth = (mHitDice * mLevel + mConstitutionBonus);
}

void Player::FullHeal() {
    mHealth = mMaxHealth;
    mSpecialAttackTotal = 3;
    mUltimateAttackTotal = 3;
}
void Player::SetHitDice(int health) {
    mHitDice = health;
}
int Player::GetHealth() {
    return mHealth;
}

int Player::GetMaxHealth() {
    return mMaxHealth;
}

void Player::SetHealth(int health) {
     mHealth = health; 
}
