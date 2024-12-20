#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Player.h"



using std::vector;
using std::string;
using std::cin;

enum class ItemType {
    Gear,
    Consumable,
    Weapon,
    Item
    // Add other types as needed
};

struct Effect {
    int healing;
    int damage;
    int duration;
    int damageReduction;

    // Constructor with default values
    Effect(int healing = 0, int damage = 0, int duration = 0, int damageReduction = 0)
        : healing(healing), damage(damage), duration(duration), damageReduction(damageReduction) {
    }
};

class Inventory {
public:
    static Inventory* Instance();
    static void Release();
    
    Inventory(const string& name, const Effect effect, int quantity, int value, bool consumable, ItemType type, bool equipped);
    Inventory(const string& name, const Effect effect, int quantity, int value, bool consumable, ItemType type);
    ~Inventory();

    void AddItem();
    void RemoveItem();
    void ListGearItems() const;
    int GetItemQuantity();
    void DecreaseQuantity(int howMany);
    void SetItemQuantity(int howMany);
    vector<Inventory> PlayerInventory;
    vector<Inventory> MerchantInventory;
    vector<Inventory> BlacksmithItems;
    //vector<Inventory> getEquippedGear();
    void EquipGear();
    void Use();
    bool IsUsable();
    void UnequipGear();
    ItemType GetType() const;
    string GetItemName() const;
    Effect GetEffect() const;
    void OpenInventory(Player* player); //function to open the inventory  
    void ListEquippedItems(Player* player); 
    int GetGoldQuantity() const; //get the gold quantity  
    void IncreaseGold(Player* player, int amount); //increase the gold quantity   
    void DecreaseGold(Player* player, int amount); //decrease the gold quantity   
    int SellEquipItem(Player* player, int index); //sell the equipment items
    void RunBlacksmith(Player* player); //run the blacksmith
    void RunGeneralStore(Player* player); //run the general store 
    int SellGeneralItem(Player* player, int index); //sell the general items  
    int PurchaseEquipItem(Player* player, int index); //purchase the equipment items 
    int PurchaseGeneralItem(Player* player, int index); //purchase the general items    

private:
    Inventory() = default;
    static Inventory* sInstance;

    string mName;
    Effect mEffect;
    int mQuantity;
    int mValue;
    bool mConsumable;
    bool mEquipped;
    bool mEquipment;
    ItemType mType;

};