//
// Created by amiar on 23/10/2024.
//

#include "Warrior.h"

// La classe 'WARRIOR' a 50% plus d'attaque que les autres classes
Warrior::Warrior(const string &name) : Hero(name) {
    m_attack = m_attack*(1+(50.0/100));
}


// Override de la fonction, un 'WARRIOR' peut uniquement équiper des SWORD en arme
void Warrior::equipWeapon(Weapon* ptr_sword) {
    // Si le l'item envoyé n'est pas un SWORD = erreur
    if (typeid(*ptr_sword) != typeid(Sword)) {
        cout << "Un GUERRIER ne peux pas equiper autre chose qu'une 'SWORD'" << endl;
        return;
    }
    // Sinon on défini l'arme dans 'm_weapon'
    m_weapon = ptr_sword;
    cout << "Vous avez equiper une 'SWORD'" << endl;

}

// Override de la fonction, Equiper une SWORD provenant de l'inventaire
void Warrior::equipFromInventory(const int indexItem) {
    // Si l'index renvoi a un item autre qu'une 'SWORD' = erreur
    if (m_inventory->getItemType(indexItem) != "SWORD") {
        cout << "Un WARRIOR ne peut pas equiper '" << m_inventory->getItemType(indexItem) << "'" << endl;
        return;
    }
    // Si une épée est déjà équipée = erreur
    if (m_weapon != nullptr) {
        cout << "Impossible d'equiper une arme tant que vous avez une arme deja equipee" << endl;
        return;
    }
    // Si l'item est une SWORD on l'ajoute a 'm_weapon'
    m_weapon = m_inventory->equipSword(indexItem);
    cout << "Vous avez equipe " << m_weapon->getName() << endl;
}

void Hero::attackMonster(Hero *hero, Monster *monster) {
    monster->setHealth(monster->getHealth()-hero->getAttack());
    monster->isMonsterDead(hero);
}