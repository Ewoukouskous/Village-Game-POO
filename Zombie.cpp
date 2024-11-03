//
// Created by ninol on 03/11/2024.
//

#include "Zombie.h"

Zombie::Zombie() {
    m_name = "Zombie";
    m_health = 30;
    m_attack = 10;
    m_defense = 7;
    m_gold = 30;
}

string Zombie::showStats() const {
    string str = "Type : " + m_name + "\n"
    + "Health: " + to_string(m_health) + "\n"
    + "Attack : " + to_string(m_attack) + "\n"
    + "Defense : " + to_string(m_defense) + "\n"
    + "Gold : " + to_string(m_gold) + "\n";

    return str;
}
