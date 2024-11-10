//
// Created by amiar on 23/10/2024.
//

#ifndef HERO_H
#define HERO_H

#include "Inventory.h"

class PotionHeal;
class PotionStrength;
class PotionDefense;
class Weapon;
class Item;
class Village;
class Building;
class Monster;

// The abstract class 'Hero' has for child :
// - 'Warrior' : Can only equip a 'Sword', can't equip 'Shield'
// he got 50% more 'm_attack'
//
// - 'Paladin' : Can only equip a 'Sword' and a 'Shield'
//
// - 'Wizard' : Can only equip a 'Wand', can't equip 'Shield'
// and got a 20% chance to dodge ('m_dodge = 20')

class Hero {
//  By default, all heroes got for attributes :
private:
    string m_name; // a name
    int m_gold; // = 50
    Village* m_heroVillage;

// All the attributes that can be changed depending on the type:
protected:
    string m_type;
    int m_health; // = 100
    int m_attack; // By default = 10 | 'Warrior' = +50%
    int m_defense; // = 5
    int m_dodge; // By default = 0 | 'Wizard' = 20
    Weapon* m_weapon = nullptr; // All of us can get a weapon
    Inventory* m_inventory = nullptr; // All of us get an Inventory (made by the constructor)
    Building* m_currentLocation = nullptr;

public:

    // To create a Hero only a name is necessary
    Hero(const string &name);
    virtual ~Hero() {delete m_inventory; delete m_weapon;}
    // The Hero introduce himself ( Name + class)
    void introduceHimself() const;
    // Pure virtual method to equip a weapon (The classes will get restrictions)
    virtual void equipWeapon(Weapon* ptr_weapon) = 0;
    // Store the weapon in the inventory and unequip it (if there is free room left in it)
    void storeWeapon();
    // Delete and DESTROY the weapon equipped by the Hero
    void dropWeapon();
    // Virtual pure method that allow to equip a Weapon of a Shield from the Inventory
    // (Some classes won't be able to equip a Shield)
    virtual void equipFromInventory(const int indexItem) =0;

    virtual void drinkFromInventory(const int indexItem);

    // Add a pointer of Item in the Inventory
    void addToInventory(Item* ptr_item) const;
    // We delete and destroy an Item from the Inventory
    void removeFromInventory(const int indexItem) const;

    void attackMonster(Monster *monster);

    virtual void beingHit(int mobAttack);

    // A series of strings containing all the hero's stats.
    virtual string showStats() const;

    void travel(Building *ptr_building);

    void leave();

    void buyItem(Item *copyItem);

    // SETTERS
    void setHealth(int health) {
        m_health = health;
    }
    void setGold(int gold) {
        m_gold = gold;
    }
    void setAttack(int attack) {
        m_attack = attack;
    }
    void setCurrentLocation(Building *ptr_location) {
        m_currentLocation = ptr_location;
    }

    // Getters
    const string& getName() const {
        return m_name;
    }

    virtual const string& getType() const = 0;

    const int& getHealth() const {
        return m_health;
    }
    virtual int getDefense() const {
        return m_defense;
    }
    const int& getGold() const {
        return m_gold;
    }
    int getAttack() const {
        // The attack will depend of the weapon equipped
        int attack = m_attack;
        if (m_weapon != nullptr) {
            attack += m_weapon->getDamage();
        }
        return attack;
    }
    const int& getDodge() const {
        return m_dodge;
    }

    const string getWeaponName() const {
        if (m_weapon == nullptr) {
            return "NULL WEAPON";
        }
        return m_weapon->getName();
    }
    Weapon* getWeapon() const {
        return m_weapon;
    }

    string getInventory() const {
        return m_inventory->getInventoryList();
    }

    unsigned long getInventorySize() const {
        return m_inventory->getInventorySize();
    }

    // Contain all the Hero basic actions
    vector<string> getBasicActions() const;
    // Contain all the Inventory related actions
    virtual vector<string> getInventoryActions() const;

    Building* getCurrentLocation() const {
        return m_currentLocation;
    }
    Village* getHeroVillage() const { return m_heroVillage; }
};

#endif //HERO_H