//
// Created by amiar on 23/10/2024.
//

#include "Hero.h"
#include "PotionHeal.h"
#include "PotionStrength.h"
#include "PotionDefense.h"
#include "Weapon.h"
#include "Item.h"
#include "Monster.h"
#include "Village.h"
#include "Building.h"

    // Default attributes of an Hero
Hero::Hero(const string &name) {
    m_name = name;
    m_health = 100;
    m_defense = 5;
    m_gold = 50;
    m_attack = 10;
    m_dodge = 0;
    m_inventory = new Inventory();
    m_heroVillage = new Village("FroopyLand");
}

void Hero::introduceHimself() const {
    cout << "Hello im " << m_name << " and im a " << m_type << endl;
}

    // Stock the actual weapon in the inventory
void Hero::storeWeapon() {
    if (m_weapon==nullptr) {
        cout << "You doesn't have any weapon equipped" << endl;
        return;
    }
    // If there is no place in the inventory, the hero cant stock his weapon
    if (m_inventory->getInventorySize() > 9) {
        cout << "Your inventory is full, you can't store your weapon in it." << endl;
        return;
    }
    // If there's still a place, it stock the weapon and unequip it
    addToInventory(m_weapon);
    cout << "You have just put your " << m_weapon->getName() <<" in your inventory" <<endl;
    m_weapon = nullptr;
    }

    // Delete the Weapon* pointer that the hero equipped, and unequip it
void Hero::dropWeapon() {
    delete m_weapon;
    m_weapon = nullptr;
}

    // Add the pointer of the item in your inventory
void Hero::addToInventory(Item *ptr_item) const {
    m_inventory->addItem(ptr_item);
}
    // We take out and delete the item asked
void Hero::removeFromInventory(const int indexItem) const {
    m_inventory->removeItem(indexItem);
}

    // Drink the potion asked, add the effect of it, remove it from the inventory and delete it
void Hero::drinkFromInventory(const int indexItem) {
    // Check if the index isn't out of range
    if (indexItem >= m_inventory->getInventorySize()) {
        cout << "Error : Index Out Of Range" << endl;
        return;
    }
    Item* item = m_inventory->getItem(indexItem);

    // We apply the effect by taking in fact the type of the potion
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
        // If attack is above 20, we can't drink more strength potion ( 20 is the max amount of attack )
        if (m_attack >= 20) {
            cout << "You don't think you are strong enough to drink this ?" <<endl;
            return;
        }
        m_attack += strengthPotion->use();
        cout << "Your basic attack (without weapon) is now : " << m_attack << endl;
        m_inventory->removeItem(indexItem);
        return;
    }
    if (auto* defensePotion = dynamic_cast<PotionDefense*>(item)) {
        // Same for the attack but with the defense
        if (m_defense >= 20) {
            cout << "You can't drink Potion of Defense anymore (it's not fun if a Zombie can't hit you ^^)" <<endl;
            return;
        }
        m_defense += defensePotion->use();
        cout << "Your basic defense (without shield) is now : " << m_defense << endl;
        m_inventory->removeItem(indexItem);
        return;
    }
    cout << "The choosen item isn't a potion" << endl;
}

    // Set damages to the Monster by taking the Hero's attack
void Hero::attackMonster(Monster *monster) {
    int globalAttack = getAttack() - monster->getDefense();
    if (m_weapon != nullptr) {
        m_weapon->use();
    }
    if (globalAttack <= 0) {
        cout << "You are so weak you did 0 damage ( noob )" << endl;
    } else {
        if (monster->getHealth()-globalAttack<=0) {monster->setHealth(0);}
        else {monster->setHealth(monster->getHealth()-globalAttack);}

        cout << getName() << " deal " << globalAttack << " damage to " << monster->getName() << endl;
        cout << monster->getName() << " have now "<< monster->getHealth()<< " hp" << endl;
        if (monster->getHealth() <= 0) {
            cout << monster->getName() << " is now dead" << endl;
            setGold(monster->getGold() + getGold());
            delete monster;
        }
    }

}

    // List all the statistics of the Hero
string Hero::showStats() const {
    int attack = m_attack;
    if (m_weapon != nullptr) {
        // If the hero have a weapon, it shows his attack with the damages of the weapon
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

    // The hero can takes damages from monsters
void Hero::beingHit(int mobAttack) {
    cout << "You receive " << mobAttack << " damages" << endl;
    if (getHealth() <= 0) {
        cout << "Hero dead" << endl;
    }
}

    // A list of the actions the Hero can do
vector<string> Hero::getBasicActions() const{
    vector<string> actions = {"Introduce Yourself","Inventory","Travel","Show Stats"};
    return actions;
}

    // A list of the actions possible by the Hero in hix inventory
vector<string> Hero::getInventoryActions() const {
    vector<string> actions = {"Show Inventory","Remove From Inventory","Store current weapon","Equip from inventory","Drink from inventory"};
    return actions;
}

    // Function that change the current location of the hero, he can travel between Buildings
void Hero::travel(Building *ptr_building) {
    setCurrentLocation(ptr_building);
    ptr_building->setHeroInside(this);
    cout << ptr_building->introduceBuilding() << endl;
}

    // He can leave Building, nullptr is equal to the main place of the village
void Hero::leave() {
    getCurrentLocation()->setHeroInside(nullptr);
    setCurrentLocation(nullptr);
}

    // function called when the Hero buy items in the shop
void Hero::buyItem(Item *copyItem) {
    setGold(getGold()-copyItem->getPrice());
    addToInventory(copyItem);
}