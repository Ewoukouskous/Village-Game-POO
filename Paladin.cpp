//
// Created by amiar on 25/10/2024.
//

#include "Paladin.h"
Paladin::Paladin(const string &name) : Hero(name) {
    m_type = "Paladin";
}

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

// Stocke le shield actuel dans l'inventaire
void Paladin::storeShield() {
    if (m_shield==nullptr) {
        cout << "You doesn't have any shield equipped" << endl;
        return;
    }
    // S'il reste moins d'UNE place dans l'inventaire on ne peut pas ranger le shield à l'intérieur
    if (m_inventory->getInventorySize() > 9) {
        cout << "Your inventory is full, you can't store your shield in it." << endl;
        return;
    }
    // Si une place est restante on ajoute le shield dans l'inventaire, puis on le désequippe
    addToInventory(m_shield);
    cout << "You have just put your " << m_shield->getName() <<" in your inventory" <<endl;
    m_shield = nullptr;
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


vector<string> Paladin::getInventoryActions() const {
    vector<string> actions = {"Show Inventory","Add to inventory","Remove From Inventory","Store current weapon","Store current shield","Equip from inventory","Drink from inventory"};
    return actions;
}

