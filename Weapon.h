//
// Created by amiar on 23/10/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"


class Weapon : public Item{
protected:
    string m_weaponType;
    int m_damage;
    int m_durability;
public:
    Weapon(const int &damage, const int &durability, const string &name, const int &price);
    // Appelée lorsque un joueur l'utilise (baisse sa durabilité)
    // Une fois la durabilité a 0 l'arme casse et ne fait plus de dégats
    virtual void weaponBreak() = 0;
    string getAsString() const;

    // GETTERS
    const string & getWeaponType() const {
        return m_weaponType;
    }
    const int & getDamage() const {
        return m_damage;
    }
    const int & getDurability() const {
        return m_durability;
    }
};



#endif //WEAPON_H
