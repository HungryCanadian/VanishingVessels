#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::string;

class Enemy {
private:
    string mName;
    int mDamage;
    int mHealth;
    int mGold;
    int mExperience;

public:
    Enemy(const string& name, int damage = 1, int health = 10, int mGold = 10, int mExperience = 100);
    Enemy();

    int Attack() const;
    void TakeDamage(int damage);
    bool IsAlive() const;

    // Getter for the enemy's name
    string GetName() const;

    // Getter for the enemy's health
    int GetHealth() const;

    // Getter for the enemy's attack damage
    int GetAttack() const;

    int GetGold() const;

    int GetExp() const;
};