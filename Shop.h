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
public:
    Shop();

    string showInventory();
    Item* getItemCopy(int index);
    void sellItem(int itemIndex);

    string getBuildingType() override;
    string introduceBuilding() override;

    ~Shop();
};



#endif //SHOP_H
