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
        cout << "Un GUERRIER ne peux pas equiper autre chose qu'une 'SWORD'" << endl;
        return;
    }
    // Else we define the weapon in m_weapon
    m_weapon = ptr_sword;
    cout << "Vous avez equiper une 'SWORD'" << endl;

}

// Override warrior can just equip a sword from the inventory
void Warrior::equipFromInventory(const int indexItem) {
    // If index send isn't a sword : error
    if (m_inventory->getItemType(indexItem) != "SWORD") {
        cout << "Un WARRIOR ne peut pas equiper '" << m_inventory->getItemType(indexItem) << "'" << endl;
        return;
    }
    // If a sword's already equiped : error
    if (m_weapon != nullptr) {
        cout << "Impossible d'equiper une arme tant que vous avez une arme deja equipee" << endl;
        return;
    }
    // Else we definie m_weapon with the weapon
    m_weapon = m_inventory->equipSword(indexItem);
    cout << "Vous avez equipe " << m_weapon->getName() << endl;
}
