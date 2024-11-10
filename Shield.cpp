//
// Created by amiar on 25/10/2024.
//

#include "Shield.h"

Shield::Shield(const int &defense, const int &durability, const string &name, const int &price) :Item(name,price) {
    m_itemType = "SHIELD";
    m_defense = defense;
    m_durability = durability;
}

string Shield::getType() {
    return m_itemType;
}

    // Use 1 durability when the shield blocks an attack and tell it to you when it is broken
int Shield::use() {
    if (m_durability <= 0 ) {
        cout << "Your Shield is broken, it won't protect you." << endl;
        return m_defense;
    }
    m_durability --;
    if (m_durability <= 0) {
        shieldBreak();
    }
    return m_defense;
}

    // break the shield
void Shield::shieldBreak() {
    cout << "Your Shield just broke" << endl;
    m_defense = 0;
    m_name += " [BROKEN]";
}