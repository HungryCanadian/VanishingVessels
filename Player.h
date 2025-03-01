#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Race.h"

class Player {
public:
    static Player* Instance(std::string name = "test",
        std::string characterRace = "Unknown",
        std::string characterClass = "Civilian",
        int level = 1, int experience = 0,
        int expToLevel = 100, int gold = 150);


    // Getter and Setter for Race
    std::string GetRace();
    void SetRace(std::string race);

    // Getter and Setter for Class
    std::string GetClass();
    void SetClass(std::string charClass);

    // Other Player methods
    void SetAttributes();
    void CalculateBonuses();
    void RaceBonuses();
    void calculateHealth();
    void GenerateRandomStats();
    int GetHealth();
    int GetMaxHealth();
    void SetHealth(int health);
    void SetHitDice(int health);
    int GetStrength();
    int GetDexterity();
    int GetConstitution();
    int GetIntelligence();
    int GetWisdom();
    int GetCharisma();
    int GetStrengthBonus();
    int GetDexterityBonus();
    int GetConstitutionBonus();
    int GetIntelligenceBonus();
    int GetWisdomBonus();
    int GetCharismaBonus();
    int GetDamageReduction();
    void RemoveDamageReduction(int amount);
    void AddDamageReduction(int amount);
    int GetGold();
    void SubtractGold(int value);
    void AddGold(int value);
    void AddEXP(int value);
    void LevelUp();
    int GetLevel();
    void TakeDamage(int value);
    bool IsAlive();
    int Attack();
    void Attack(int damage);

    void FullHeal();
    void Heal(int heal);


    // Singleton cleanup
    static void Release();

private:
    // Private constructor to prevent external instantiation
    Player(std::string name = "test",
        std::string characterRace = "Unknown",
        std::string characterClass = "Civilian",
        int level = 1, int experience = 0,
        int expToLevel = 100, int gold = 150);

    // Player's internal attributes
    std::string mName;
    int mHealth=10;
    int mGold;
    int mLevel=1;
    int mDamage;
    int mMaxHealth=10;
    int mExperience;
    int mExpToLevel=100;
    int mSpecialAttackTotal = 3;
    int mUltimateAttackTotal = 1;
    int totalDamageReduction = 0;
    int mAttack = 3;

    //base Scores
    int mStrength;
    int mConstitution=10;
    int mDexterity;
    int mIntellect;
    int mWisdom;
    int mCharisma;
    int mStrengthRaceBonus=0;
    int mConstitutionRaceBonus=0;
    int mDexterityRaceBonus=0;
    int mIntellectRaceBonus=0;
    int mWisdomRaceBonus=0;
    int mCharismaRaceBonus=0;
    int mStrengthBonus;
    int mDexterityBonus;
    int mConstitutionBonus=0;
    int mIntellectBonus;
    int mWisdomBonus;
    int mCharismaBonus;
    int mHitDice;

    std::string mRace;
    std::string mCharClass;

    // Static instance for Singleton pattern
    static Player* sInstance;
};
