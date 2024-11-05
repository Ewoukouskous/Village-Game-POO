//
// Created by ninol on 01/11/2024.
//

#include "Slime.h"

Slime::Slime() {
    m_name = "Slime";
    m_health = 15;
    m_attack = 6;
    m_defense = 2;
    m_gold = 10;
}

string Slime::showStats() const {
    string str = "Type : " + m_name + "\n"
    + "Health: " + to_string(m_health) + "\n"
    + "Attack : " + to_string(m_attack) + "\n"
    + "Defense : " + to_string(m_defense) + "\n"
    + "Gold : " + to_string(m_gold) + "\n";

    return str;
}

