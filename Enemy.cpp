#include "Enemy.h"

// Constructor
Enemy::Enemy(const string& name, int damage, int health, int gold, int experience)
    : mName(name), mDamage(damage), mHealth(health), mGold(gold), mExperience(experience) {
}

Enemy::Enemy() { }

// Attack method
int Enemy::Attack() const {
    return mDamage;
}

// Method to take damage
void Enemy::TakeDamage(int damage) {
    mHealth -= damage;
    if (mHealth < 0) {
        mHealth = 0; // Ensure health does not go below zero
    }
}

// Check if enemy is alive
bool Enemy::IsAlive() const {
    return mHealth > 0;
}

int Enemy::GetGold() const {
    return mGold;
}

int Enemy::GetExp() const {
    return mExperience;
}

// Getter for the enemy's name
string Enemy::GetName() const {
    return mName;
}

// Getter for the enemy's health
int Enemy::GetHealth() const {
    return mHealth;
}

// Getter for the enemy's attack damage
int Enemy::GetAttack() const {
    return mDamage;
}
