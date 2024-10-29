//
// Created by amiar on 23/10/2024.
//

#include "Hero.h"
// Les stats par défaut d'un hero
Hero::Hero(const string &name) {
    m_name = name;
    m_health = 100;
    m_defense = 5;
    m_gold = 50;
    m_attack = 10;
    m_dodge = 0;
    m_inventory = new Inventory();
}

// Supprime le pointeur Weapon* que le hero a équipé et DETRUIT le 'WEAPON'
void Hero::dropWeapon() {
    delete m_weapon;
    m_weapon = nullptr;
}


// Ajoute un pointeur d'item dans l'inventaire
void Hero::addToInventory(Item *ptr_item) const {
    m_inventory->addItem(ptr_item);
}
// On retire et detruit un item de l'inventaire
void Hero::removeFromInventory(const int indexItem) const {
    m_inventory->removeItem(indexItem);
}


// Permet de lister toutes les stats d'un héro
string Hero::showStats() const {
    int attack = m_attack;
    if (m_weapon != nullptr) {
        // Si le héro a eu arme on affiche son attaque en ajoutant les dégats de l'arme
        attack += m_weapon->getDamage();
    }
    string str = "Name : " + m_name + " | "
    + "Health : " + to_string(m_health) + " | "
    + "Defense : " + to_string(m_defense) + " | "
    + "Attack : " + to_string(attack) + " | "
    + "Dodge : " + to_string(m_dodge) + " | "
    + "Gold : " + to_string(m_gold) + " |\n";
    return str;
}

