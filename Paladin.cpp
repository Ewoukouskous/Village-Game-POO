//
// Created by amiar on 25/10/2024.
//

#include "Paladin.h"
#include "PotionDefense.h"
#include "PotionHeal.h"
#include "PotionStrength.h"

Paladin::Paladin(const string &name) : Hero(name) {
    m_type = "Paladin";
}

// Override of the function, The paladin can equip swords
void Paladin::equipWeapon(Weapon* ptr_sword) {
    // If the item isn't a sword : error
    if (typeid(*ptr_sword) != typeid(Sword)) {
        cout << "A Paladin can't equip a weapon else than a SWORD" << endl;
        return;
    }
    // else we define the sword in m_weapon
    m_weapon = ptr_sword;
    cout << "You just equipped " << m_shield->getName() << endl;
}

// Function specific to the paladin. He is alone who can equip shield
void Paladin::equipShield(Shield* ptr_shield) {
    // If the item isn't a shield : error
    if (typeid(*ptr_shield) != typeid(Shield)) {
        cout << "The selected item is not a SHIELD" << endl;
        return;
    }
    // If the hero had already a shield, he cannot equip another
    if (m_shield != nullptr) {
        cout << "You can't equip this because you already has a SHIELD equipped" << endl;
        return;
    }
    // Else we define the shield in m_shield
    m_shield = ptr_shield;
    cout << "You just equipped " << m_shield->getName() << endl;

}

// Stock the current shield in the inventory
void Paladin::storeShield() {
    if (m_shield==nullptr) {
        cout << "You doesn't have any shield equipped" << endl;
        return;
    }
    // If the inventory's full we can't store it
    if (m_inventory->getInventorySize() > 9) {
        cout << "Your inventory is full, you can't store your shield in it." << endl;
        return;
    }
    // Else we add it in the inventory and set m_shield to null
    addToInventory(m_shield);
    cout << "You have just put your " << m_shield->getName() <<" in your inventory" <<endl;
    m_shield = nullptr;
}

// Delete the pointer and the SHield
void Paladin::dropShield() {
    delete m_shield;
    m_shield = nullptr;
}

// Override , Equip a shield and a sword
void Paladin::equipFromInventory(const int indexItem) {
    // If the item is already equipped : error
    if (m_weapon != nullptr && m_inventory->getItemType(indexItem) == "SWORD" || m_shield != nullptr && m_inventory->getItemType(indexItem) == "SHIELD") {
        cout << "Impossible to equip '"<< m_inventory->getItemType(indexItem) << "' until you already have one equipped" << endl;
        return;
    }
    // If the item is a sword, we add it in m_sword
    if (m_inventory->getItemType(indexItem) == "SWORD") {
        m_weapon = m_inventory->equipSword(indexItem);
        cout << "You just equipped " << m_weapon->getName() << endl;
        return;
    }
    // If the item is a Shield, we add it in m_sword
    if (m_inventory->getItemType(indexItem) == "SHIELD") {
        m_shield = m_inventory->equipShield(indexItem);
        cout << "You just equipped " << m_shield->getName() << endl;
        return;
    }
    // If the item isn't a shield or a sword : error
    cout << "A PALADIN can't equip a '" << m_inventory->getItemType(indexItem) << "'" << endl;
}

void Paladin::drinkFromInventory(const int indexItem) {
    // check if the index isn't out of range
    if (indexItem >= m_inventory->getInventorySize()) {
        cout << "Error : Index Out Of Range" << endl;
        return;
    }
    Item* item = m_inventory->getItem(indexItem);

    // Depending on the potion, we apply the effect
    if (auto* healPotion = dynamic_cast<PotionHeal*>(item) ) {
        // If the effect of the potion + the health of the hero is above 100, we apply the life of the hero to 100 ( maximum life )
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
        // If effectPotion + m_attack is above 100 we set it to 100
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
        // A paladin can't drink PotionDefense (it will be overcheated)
        cout << "You can't drink a Potion of Defense, you fell in it when you were young :)" << endl;
        cout << "You should think about using a shield instead" << endl;
        return;
    }
    cout << "The chosen item isn't a potion" << endl;
}

string Paladin::showStats() const {
    int attack = m_attack;
    int defense = m_defense;
    if (m_weapon != nullptr) {
        // If the hero had a weapon , we show his damages with the damages of the weapon
        attack += m_weapon->getDamage();
    }
    if (m_shield != nullptr) {
        // If the hero had a shield, we show the defense with the defense of the shield
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
    vector<string> actions = {"Show Inventory","Remove From Inventory","Store current weapon","Store current shield","Equip from inventory","Drink from inventory"};
    return actions;
}

void Paladin::beingHit(const int mobAttack) const {
    cout << "You receive " << mobAttack << " damages" << endl;
    if (m_shield != nullptr) {
        cout << "You have cancelled "<< mobAttack-getDefense() <<" damages with your shield" << endl;
        m_shield->use();
    }
    if (getHealth() <= 0) {
        cout << "Hero dead" << endl;
    }
}