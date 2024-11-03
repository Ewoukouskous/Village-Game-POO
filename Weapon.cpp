//
// Created by amiar on 23/10/2024.
//

#include "Weapon.h"

Weapon::Weapon(const int &damage, const int &durability, const string &name, const int &price)
            : Item(name,price) {
    m_damage = damage;
    m_durability = durability;
}

string Weapon::getAsString() const {
    string str = "| Type : " + m_weaponType + " | "
    + "Name : " + m_name + " | "
    + "Damage : " + to_string(m_damage) + " | "
    + "Price : " + to_string(m_price) + " |";
    return str;
}

void Weapon::weaponBreak() {
    cout << "Your weapon just broke." << endl;
    m_damage = 0;
}
