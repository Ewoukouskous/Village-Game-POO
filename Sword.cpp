//
// Created by amiar on 23/10/2024.
//

#include "Sword.h"

Sword::Sword(const int &damage,const int &durability, const string &name, const int &price)
        : Weapon(damage,durability,name,price) {
    m_weaponType = "SWORD";
}

string Sword::getType() {
    return m_weaponType;
}

    // use one durability when the sword is used, tell it when it is broken
int Sword::use() {
    if (m_durability <= 0 ) {
        cout << "Your Sword is broken, you won't deal any damage with it." << endl;
        return m_damage;
    }
    m_durability --;
    cout << "You're attacking with your sword"<<endl;
    if (m_durability <= 0) {
        weaponBreak();
    }
    return m_damage;
}

void Sword::weaponBreak() {
    cout << "Your Sword just broke" << endl;
    m_damage = 0;
    m_name += " [BROKEN]";
}
