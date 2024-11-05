//
// Created by amiar on 23/10/2024.
//

#include "Hero.h"
#include "Monster.h"

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

void Hero::attackMonster(Monster *monster) {
    int globalAttack = getAttack() - monster->getDefense();
    cout << globalAttack << endl;
    if (globalAttack < 0) {
        cout << "you are so weak you did 0 damage ( noob )" << endl;
    } else {
        monster->setHealth(monster->getHealth()-globalAttack);
        cout << getName() << " deal " << globalAttack << " damage to " << monster->getName() << endl;
        cout << monster->getName() << " have now "<< monster->getHealth()<< " hp" << endl;
        if (monster->getHealth() <= 0) {
            cout << monster->getName() << " is now dead" << endl;
            setGold(monster->getGold() + getGold());
            delete monster;
        }
    }
    if (m_weapon != nullptr) {
        cout <<
        m_weapon->use();
    }
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

void Hero::beingHit(int mobAttack) {
    cout << "You receive " << mobAttack << " damages" << endl;
    if (getHealth() <= 0) {
        cout << "Hero dead" << endl;
        // add GameOver
    }
}
