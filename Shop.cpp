//
// Created by ninol on 07/11/2024.
//

#include "Shop.h"

Shop::Shop(): Building("Shop") {
    PotionHeal *small_potion_heal = new PotionHeal("Small Potion of Heal", 30, 25);
    PotionHeal *big_potion_heal = new PotionHeal("Big Potion of Heal", 100, 90);
    PotionDefense *potion_defense = new PotionDefense("Potion of Defense", 5, 70);
    PotionStrength *potion_strength = new PotionStrength("Potion of Strength", 2, 70);

    Sword *little_stick = new Sword(3, 10, "Little Stick", 5);
    Sword *iron_sword = new Sword(10, 20, "Iron Sword", 35);
    Sword *peacekeeper = new Sword(25, 30, "Peacekeeper", 100);

    Wand *magic_stick = new Wand(5, 15, "Magic Stick", 5);
    Wand *elderberry_wand = new Wand(18, 30, "Elderberry Sword", 65);
    Wand *avada_kedavra = new Wand(1000, 1, "Avada Kedavra", 75);

    Shield *wooden_plank = new Shield(3, 5, "Wooden Plank", 10);
    Shield *hyrule_shield = new Shield(15, 20, "Hyrule's Shield", 30);
    Shield *tower_shield = new Shield(40, 25, "Tower Shield", 85);

    m_shopInventory.push_back(small_potion_heal);
    m_shopInventory.push_back(big_potion_heal);
    m_shopInventory.push_back(potion_defense);
    m_shopInventory.push_back(potion_strength);
    m_shopInventory.push_back(little_stick);
    m_shopInventory.push_back(iron_sword);
    m_shopInventory.push_back(peacekeeper);
    m_shopInventory.push_back(magic_stick);
    m_shopInventory.push_back(elderberry_wand);
    m_shopInventory.push_back(avada_kedavra);
    m_shopInventory.push_back(wooden_plank);
    m_shopInventory.push_back(hyrule_shield);
    m_shopInventory.push_back(tower_shield);

}

Item* Shop::getItemCopy(int index) {
    if (index >= 0 && index < m_shopInventory.size()) {
        return m_shopInventory[index]->clone();  // Utilise clone pour obtenir une copie
    }
    return nullptr;
}


string Shop::showInventory() {
    string list = "";
    for (unsigned int i = 0; i < m_shopInventory.size(); i++) {
        if (i == 3 || i == 6 || i == 9 || i == 12) {
            list += "\n";
        }
        list += "|[index " + to_string(i) + "]: " + m_shopInventory[i]->getName() + "|  ";
    }
    return list;
}

void Shop::sellItem(int itemIndex) {
    if (itemIndex < 0 || itemIndex >= m_shopInventory.size()) {
        cout << "Invalid item index" << endl;
        return;
    }
    if (m_heroInside->getGold() >= m_shopInventory[itemIndex]->getPrice() && m_heroInside->getInventorySize() < 10) {
        cout << "Dont forget ! neither returned or exchanged !! ;] " << endl;
        m_heroInside->buyItem(getItemCopy(itemIndex));
        return;
    }
    cout << "You have no place left in your inventory or you can't afford this item" << endl;
}

string Shop::getBuildingType() {
    return "Shop";
}

string Shop::introduceBuilding() {
    string result = "Welcome to the Shop! You can buy everything I have here!";
    return result;
}

Shop::~Shop() {
    for (int i = 0; i < m_shopInventory.size(); i++) {
        delete m_shopInventory[i];
    }
}

