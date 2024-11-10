//
// Created by amiar on 23/10/2024.
//

#include "Warrior.h"

// Class warrior has 50% more damage ( big fist )
Warrior::Warrior(const string &name) : Hero(name) {
    m_type = "Warrior";
    m_attack = m_attack*(1+(50.0/100));
}

// Override A warrior can just equip sword
void Warrior::equipWeapon(Weapon* ptr_sword) {
    // If the item isn't a sword : error
    if (typeid(*ptr_sword) != typeid(Sword)) {
        cout << "A WARRIOR can't equip anything else than a 'SWORD'" << endl;
        return;
    }
    // Else we define the weapon in m_weapon
    m_weapon = ptr_sword;
    cout << "You just equipped a 'SWORD'" << endl;

}

// Override warrior can just equip a sword from the inventory
void Warrior::equipFromInventory(const int indexItem) {
    // If index send isn't a sword : error
    if (m_inventory->getItemType(indexItem) != "SWORD") {
        cout << "A WARRIOR can't equip a '" << m_inventory->getItemType(indexItem) << "'" << endl;
        return;
    }
    // If a sword's already equiped : error
    if (m_weapon != nullptr) {
        cout << "Impossible to equip a weapon until you got one equipped" << endl;
        return;
    }
    // Else we define m_weapon with the weapon
    m_weapon = m_inventory->equipSword(indexItem);
    cout << "You just equipped " << m_weapon->getName() << endl;
}