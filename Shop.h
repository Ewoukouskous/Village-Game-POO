//
// Created by ninol on 07/11/2024.
//

#ifndef SHOP_H
#define SHOP_H

#include "Building.h"
#include "Item.h"
#include "PotionHeal.h"
#include "PotionDefense.h"
#include "PotionStrength.h"

class Shop: public Building {
private:
    vector<Item*> m_shopInventory;
    // Will display all the item of the given type (template)
    template <typename T> void displaySection(const string& sectionName) const;
public:
    Shop();

    // Display all the inventory of the Shop using displaySections()
    void displayAllItems() const;
    // Send a copy of his item
    Item* getItemCopy(int index);
    // Allow the Hero to buy something (if he can afford it or have enough space in his inventory
    void sellItem(int itemIndex);

    string getBuildingType() override;
    string introduceBuilding() override;

    ~Shop();
};



#endif //SHOP_H
