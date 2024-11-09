//
// Created by ninol on 07/11/2024.
//

#include "Shop.h"

Shop::Shop(): Building("The 'Potion & Blade' Bazaar") {

    addToInventory(new PotionHeal("Small Potion of Heal", 30, 25));
    addToInventory(new PotionHeal("Big Potion of Heal", 100, 90));
    addToInventory(new PotionDefense("Potion of Defense", 5, 70));
    addToInventory(new PotionStrength("Potion of Strength", 5, 70));

    addToInventory(new Sword(3, 20, "Little Stick", 5));
    addToInventory(new Sword(10, 45, "Iron Sword", 35));
    addToInventory(new Sword(25, 65, "Peacekeeper", 70));

    addToInventory(new Wand(5, 20, "Magic Stick", 5));
    addToInventory(new Wand(18, 45, "Elderberry Sword", 30));
    addToInventory(new Wand(1000, 1, "Avada Kedavra", 65));

    addToInventory(new Shield(5, 15, "Wooden Plank", 10));
    addToInventory(new Shield(15, 35, "Hyrule's Shield", 30));
    addToInventory(new Shield(30, 50, "Tower Shield", 85));
}

void Shop::addToInventory (Item* item) {
    m_shopInventory.push_back(item);
}

    // Clone an item, like that the shop is infinite
Item* Shop::getItemCopy(int index) {
    if (index >= 0 && index < m_shopInventory.size()) {
        return m_shopInventory[index]->clone();  // Utilise clone pour obtenir une copie
    }
    return nullptr;
}

// displaySection will display all the item of the given type present in the shop inventory
// The template is useful to call the getItemInfos() method of the concrete class given, without that it will call the method
// from Item and not of the specialisation.
template<typename T> void Shop::displaySection(const string &sectionName) const {
    {
        cout << "------------------------------------" << sectionName << "-------------------------------------\n";
        int index = 0;
        for (const auto& item : m_shopInventory) {
            if (dynamic_cast<T*>(item)) {
                cout << "[" << index << "] ";
                cout << item->getItemInfos();
            }
            ++index;
        }
        cout << "-------------------------------------------------------------------------------\n";
    }
}


void Shop::displayAllItems() const {
    std::cout << "=================================SHOP INVENTORY=================================\n";

    // Display all the Potions
    displaySection<Potion>("POTIONS");

    // Display all the Swords
    displaySection<Sword>("SWORDS");

    // Display all the Wands
    displaySection<Wand>("WANDS");

    // Display all the Shields
    displaySection<Shield>("SHIELDS");

    std::cout << "================================================================================\n";
}


void Shop::sellItem(int itemIndex) {
    if (itemIndex < 0 || itemIndex >= m_shopInventory.size()) {
        cout << "Invalid item index" << endl;
        return;
    }
    if (m_heroInside->getGold() >= m_shopInventory[itemIndex]->getPrice() && m_heroInside->getInventorySize() < 10) {
        cout << "You just buy : " << m_shopInventory[itemIndex]->getName() << " !" << endl;
        cout << "Dont forget ! neither returned or exchanged !! ;] " << endl;
        m_heroInside->buyItem(getItemCopy(itemIndex));
        return;
    }
    cout << "You have no place left in your inventory or you can't afford this item" << endl;
}

string Shop::getBuildingType() {
    return "Shop";
}

string Shop::introduceBuilding(){
    displayAllItems();
    string result = "Welcome to the Shop! You can buy everything I have here!";
    return result;
}

    // delete the shop and all the item in it
Shop::~Shop() {
    for (int i = 0; i < m_shopInventory.size(); i++) {
        delete m_shopInventory[i];
    }
}

