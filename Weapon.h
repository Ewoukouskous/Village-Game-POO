//
// Created by amiar on 23/10/2024.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <iomanip>

#include "Item.h"

class Weapon : public Item{
protected:
    string m_weaponType;
    int m_damage;
    int m_durability;
public:
    Weapon(const int &damage, const int &durability, const string &name, const int &price);
    // Called when the Hero use it (decrement his durability)
    // When the durability reach 0 the weapon break and don't deal damage anymore
    virtual void weaponBreak() = 0;
    string getAsString() const;

    // GETTERS
    const string & getWeaponType() const {
        return m_weaponType;
    }
    string getItemInfos() override {
        ostringstream itemInfos;
        itemInfos << std::left << setw(25) << m_name
            << "| Durability: " << setw(3) << m_durability
            << "| Damage: " << setw(3) << m_damage
            << "| Price: " << m_price << " gold\n";
        return itemInfos.str();
    }
    const int & getDamage() const {
        return m_damage;
    }
    const int & getDurability() const {
        return m_durability;
    }
};

#endif //WEAPON_H