//
// Created by amiar on 23/10/2024.
//

#include "Wand.h"

Wand::Wand(const int &damage,const int &durability, const string &name, const int &price)
        : Weapon(damage,durability,name,price) {
    m_weaponType = "WAND";
}

string Wand::getType() {
    return m_weaponType;
}


int Wand::use() {
    if (m_durability <= 0 ) {
        cout << "Your Wand is broken, you won't deal any damage with it." << endl;
        return m_damage;
    }
    m_durability --;
    cout << "You attack with your wand" << endl;
    if (m_durability <= 0) {
        weaponBreak();
    }
    return m_damage;
}

void Wand::weaponBreak() {
    cout << "Your Wand just broke" << endl;
    m_damage = 0;
}

