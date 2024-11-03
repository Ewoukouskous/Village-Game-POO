//
// Created by amiar on 23/10/2024.
//

#include "Wizard.h"

// La classe 'WIZARD' a 20 point de DODGE par défaut
Wizard::Wizard(const string &name) : Hero(name) {
    m_dodge = 20;
}

// Override de la fonction, un 'WIZARD' peut uniquement équiper des WAND en arme
void Wizard::equipWeapon(Weapon* ptr_weapon) {
    // Si le l'item envoyé n'est pas une WAND = erreur
    if (typeid(*ptr_weapon) != typeid(Wand)) {
        cout << "Un WIZARD ne peux pas equiper autre chose qu'une 'WAND'" << endl;
        return;
    }
    // Sinon on défini l'arme dans 'm_weapon'
    m_weapon = ptr_weapon;
    cout << "Vous avez equiper une 'WAND'" << endl;

}

// Override de la fonction, Equiper une WAND provenant de l'inventaire
void Wizard::equipFromInventory(const int indexItem) {
    // Si l'index renvoi a un item autre qu'une 'WAND' = erreur
    if (m_inventory->getItemType(indexItem) != "WAND") {
        cout << "Un WIZARD ne peut pas equiper '" << m_inventory->getItemType(indexItem) << "'" << endl;
        return;
    }
    // Si une baguette est déjà équipée = erreur
    if (m_weapon != nullptr) {
        cout << "Impossible d'equiper une arme tant que vous avez une arme deja equipee" << endl;
        return;
    }
    // Si l'item est une 'WAND' on l'ajoute a 'm_weapon'
    m_weapon = m_inventory->equipWand(indexItem);
    cout << "Vous avez equipe " << m_weapon->getName()<<endl;
}

void Hero::attackMonster(Hero *hero, Monster *monster) {
    monster->setHealth(monster->getHealth()-hero->getAttack());
    monster->isMonsterDead(hero);
}