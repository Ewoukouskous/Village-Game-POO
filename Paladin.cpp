//
// Created by amiar on 25/10/2024.
//

#include "Paladin.h"
Paladin::Paladin(const string &name) : Hero(name) {}

// Override de la fonction, un PALADIN peut uniquement équiper des SWORD en arme
void Paladin::equipWeapon(Weapon* ptr_sword) {
    // Si le l'item envoyé n'est pas un SWORD = erreur
    if (typeid(*ptr_sword) != typeid(Sword)) {
        cout << "Un PALADIN ne peux pas equiper une autre arme qu'une 'SWORD'" << endl;
        return;
    }
    // Sinon on défini l'arme dans 'm_weapon'
    m_weapon = ptr_sword;
    cout << "Vous avez equiper une 'SWORD'" << endl;

}

// Fonction en + des autres classes, seul le paladin peut équiper un SHIELD
void Paladin::equipShield(Shield* ptr_shield) {
    // Si le l'item envoyé n'est pas un SHIELD = erreur
    if (typeid(*ptr_shield) != typeid(Shield)) {
        cout << "L'item selectionné n'est pas un SHIELD" << endl;
        return;
    }
    // Si le hero a déjà un 'SHIELD' d'equipé il ne pourra pas en equiper un autre
    if (m_shield != nullptr) {
        cout << "Vous ne pouvez pas equiper ceci car vous avez deja un 'SHIELD' d'equiper" << endl;
        return;
    }
    // Sinon on défini le bouclier dans 'm_shield'
    m_shield = ptr_shield;
    cout << "Vous avez equiper un 'SHIELD'" << endl;

}
// Supprime le pointeur Shield* que le hero a équipé et DETRUIT le 'SHIELD'
void Paladin::dropShield() {
    delete m_shield;
    m_shield = nullptr;
}

// Override de la fonction, Equiper un SHIELD ou une SWORD provenant de l'inventaire
void Paladin::equipFromInventory(const int indexItem) {
    // Si l'item en question est déjà équipé = erreur
    if (m_weapon != nullptr && m_inventory->getItemType(indexItem) == "SWORD" || m_shield != nullptr && m_inventory->getItemType(indexItem) == "SHIELD") {
        cout << "Impossible d'equiper '"<< m_inventory->getItemType(indexItem) << "' tant que vous en deja 1 equiper" << endl;
        return;
    }
    // Si l'item est une SWORD on l'ajoute a 'm_weapon'
    if (m_inventory->getItemType(indexItem) == "SWORD") {
        m_weapon = m_inventory->equipSword(indexItem);
        cout << "Vous avez equipe " << m_weapon->getName() << endl;
        return;
    }
    // Si l'item est un 'SHIELD' on l'ajoute a 'm_shield'
    if (m_inventory->getItemType(indexItem) == "SHIELD") {
        m_shield = m_inventory->equipShield(indexItem);
        cout << "Vous avez equipe " << m_shield->getName() << endl;
        return;
    }
    // Si l'item n'est ni un 'SHIELD' ni une 'SWORD' = erreur
    cout << "Un PALADIN ne peut pas equiper '" << m_inventory->getItemType(indexItem) << "'" << endl;

}

string Paladin::showStats() const {
    int attack = m_attack;
    int defense = m_defense;
    if (m_weapon != nullptr) {
        // Si le héro a une arme on affiche son attaque en ajoutant les dégats de l'arme
        attack += m_weapon->getDamage();
    }
    if (m_shield != nullptr) {
        // Si le héro a un SHIELD on affiche sa defense en ajoutant la défense du SHIELD
        defense += m_shield->getDefense();
    }
    string str = "Name : " + getName() + " | "
    + "Health : " + to_string(getHealth()) + " | "
    + "Defense : " + to_string(defense) + " | "
    + "Attack : " + to_string(attack) + " | "
    + "Dodge : " + to_string(m_dodge) + " | "
    + "Gold : " + to_string(getGold()) + " |\n";
    return str;
}

void Paladin::beingHit(const int mobAttack) const {
    cout << "You receive " << mobAttack << " damages" << endl;
    if (m_shield != nullptr && m_shield->getDurability() > 0) {
        cout << "You have cancelled "<< mobAttack-getDefense() <<" damages with your shield" << endl;
        m_shield->use();
    }
    if (getHealth() <= 0) {
        cout << "Hero dead" << endl;
        // add GameOver
    }
}
