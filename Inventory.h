//
// Created by amiar on 24/10/2024.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
#include "Sword.h"
#include "Wand.h"
#include "Shield.h"

class Inventory {
private:
    vector <Item*> m_itemsArray;
    unsigned long m_sizeMax ;
public:
    Inventory();
    ~Inventory();
    // Add a pointer of Item in 'm_itemsArray'
    void addItem(Item* item);
    // Erase a pointer of Item in 'm_itemsArray' and destroy it .
    // If it's a 'SHIELD' or a 'WEAPON' ask confirmation
    void removeItem(const int indexItem);

    // Equip item methods (ne delete pas l'item de l'inventaire)
    Wand* equipWand(const int indexItem);
    Sword* equipSword(const int indexItem);
    Shield* equipShield(const int indexItem);

    // Return the type of Item present in the Inventory (SWORD,WAND,SHIELD,POTIONHEAL,POTIONSTRENGTH,POTIONDEFENSE)
    string getItemType(const int indexItem) const ;
    // Return the list of Item present in the Inventory + there index
    string getInventoryList() const;
    unsigned long getInventorySize() const {
        return m_itemsArray.size();
    }
    // Return a pointer of the Item
    Item* getItem(const int indexItem) {
        return m_itemsArray[indexItem];
    }

};

#endif //INVENTORY_H