//
// Created by amiar on 24/10/2024.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <variant>
#include <optional>
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
    // Ajoute un pointeur d'item dans 'm_itemsArray'
    void addItem(Item* item);
    // Retire un pointeur d'item dans 'm_itemsArray' et le détruit.
    // Si c'est un 'SHIELD' ou 'WEAPON' demande confirmation
    void removeItem(const int indexItem);


    // Equip item methods (ne delete pas l'item de l'inventaire)
    Wand* equipWand(const int indexItem);
    Sword* equipSword(const int indexItem);
    Shield* equipShield(const int indexItem);

    // Renvoi le type d'item présent dans l'inventaire (SWORD,WAND,SHIELD,POTIONHEAL,POTIONSTRENGTH,POTIONDEFENSE)
    string getItemType(const int indexItem) const ;
    // Renvoi la liste des items présent dans l'inventaire + leurs index
    string getInventoryList() const;
    unsigned long getInventorySize() const {
        return m_itemsArray.size();
    }
    // Renvoie un pointeur de l'item
    Item* getItem(const int indexItem) {
        return m_itemsArray[indexItem];
    }


};



#endif //INVENTORY_H
