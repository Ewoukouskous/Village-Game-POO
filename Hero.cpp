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

void Hero::introduceHimself() const {
    cout << "Hello im " << m_name << " and im a " << m_type << endl;
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

void Hero::drinkFromInventory(const int indexItem) {
    // Verification que l'index n'est pas out of range
    if (indexItem >= m_inventory->getInventorySize()) {
        cout << "Error : Index Out Of Range" << endl;
        return;
    }
    Item* item = m_inventory->getItem(indexItem);

    // En fonction du type de potion on applique son effet
    if (auto* healPotion = dynamic_cast<PotionHeal*>(item) ) {
        // Si effectPotion + m_health est plus grand que 100 on set a 100
        if (m_health + healPotion->getEffect() > 100) {
            healPotion->use();
            m_health = 100;
        } else {
            m_health += healPotion->use();;
        }
        cout << "Your HP are now : " << m_health << endl;
        m_inventory->removeItem(indexItem);
        return;
    }
    if (auto* strengthPotion = dynamic_cast<PotionStrength*>(item)){
        // Si effectPotion + m_attack est plus grand que 100 on set a 100
        if (m_attack + strengthPotion->getEffect() > 100) {
            strengthPotion->use();
            m_attack = 100;
        } else {
            m_attack += strengthPotion->use();
        }
        cout << "Your basic attack (without weapon) is now : " << m_attack << endl;
        m_inventory->removeItem(indexItem);
        return;
    }
    if (auto* defensePotion = dynamic_cast<PotionDefense*>(item)) {
        // Si effectPotion + m_defense est plus grand que 100 on set a 100
        if (m_defense + defensePotion->getEffect() > 100) {
            defensePotion->use();
            m_defense = 100;
        } else {
            m_defense += defensePotion->use();
        }
        cout << "Your basic defense (without shield) is now : " << m_defense << endl;
        m_inventory->removeItem(indexItem);
        return;
    }
    cout << "The choosen item isn't a potion" << endl;
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
