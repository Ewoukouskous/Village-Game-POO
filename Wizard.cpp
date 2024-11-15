//
// Created by amiar on 23/10/2024.
//

#include "Wizard.h"

// Class wizard had 20 dodge
Wizard::Wizard(const string &name) : Hero(name) {
    m_type = "Wizard";
    m_dodge = 20;
}

// Override, wizard can just equip wands
void Wizard::equipWeapon(Weapon* ptr_weapon) {
    // if the item isn't a wand : error
    if (typeid(*ptr_weapon) != typeid(Wand)) {
        cout << "A WIZARD can only equip a 'WAND'" << endl;
        return;
    }
    // Else we define the weapon in m_weapon
    m_weapon = ptr_weapon;
    cout << "You just equipped a 'WAND'" << endl;
}

// Override equip a wand from the inventory
void Wizard::equipFromInventory(const int indexItem) {
    // if index isn't a wand : error
    if (m_inventory->getItemType(indexItem) != "WAND") {
        cout << "A WIZARD can't equip a  '" << m_inventory->getItemType(indexItem) << "'" << endl;
        return;
    }
    // If a wand's already equipped : error
    if (m_weapon != nullptr) {
        cout << "Impossible to equip a weapon until you already have one equipped" << endl;
        return;
    }
    // else we define the wand in m_weapon
    m_weapon = m_inventory->equipWand(indexItem);
    cout << "You just equipped " << m_weapon->getName()<<endl;
}