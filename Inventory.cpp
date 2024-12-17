#include "Inventory.h"

#pragma once

Inventory::Inventory(const string& name, const Effect effect, int quantity, int value, bool consumable, ItemType type, bool equipped)
    : mName(name), mEffect(effect), mQuantity(quantity), mValue(value), mConsumable(consumable), mType(type), mEquipped(equipped) {
}

Inventory::Inventory(const string& name, const Effect effect, int quantity, int value, bool consumable, ItemType type)
    : mName(name), mEffect(effect), mQuantity(quantity), mValue(value), mConsumable(consumable), mType(type) {
}

string Inventory::GetItemName() const {
    return mName;
}

int Inventory::GetItemQuantity() {
    return mQuantity;
}

Inventory* Inventory::sInstance = nullptr;

Inventory* Inventory::Instance() {
    if (sInstance == nullptr) {
        sInstance = new Inventory();
    }

    return sInstance;
}

Inventory::~Inventory() {

}

bool Inventory::IsUsable() {
    return mConsumable;
}
