//
// Created by ninol on 03/11/2024.
//

#include "Dragon.h"

Dragon::Dragon() {
    m_name = "Dragon";
    m_health = 90;
    m_attack = 60;
    m_defense = 15;
    m_gold = 50;
}

string Dragon::showStats() const {
    string str = "Type : " + m_name + "\n"
    + "Health: " + to_string(m_health) + "\n"
    + "Attack : " + to_string(m_attack) + "\n"
    + "Defense : " + to_string(m_defense) + "\n"
    + "Gold : " + to_string(m_gold) + "\n";

    return str;
}