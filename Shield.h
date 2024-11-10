//
// Created by amiar on 25/10/2024.
//

#ifndef SHIELD_H
#define SHIELD_H

#include <iomanip>

#include "Item.h"

class Shield : public Item{
private:
    string m_itemType; // = SHIELD
    int m_defense;
    int m_durability;
public:
    Shield(const int &defense, const int &durability, const string &name, const int &price);
    // Return the type 'SHIELD'
    string getType () override;
    // Called when the Hero use it (decrement the Durability and return the quantity of defense)
    int use() override;
    // When the durability reach 0 the Shield break and protect from nothing
    void shieldBreak();

    Item* clone() const override {
        return new Shield(*this);
    }

    // GETTERS

    const int& getDurability() const {
        return m_durability;
    }

    const int& getDefense() const {
        return m_defense;
    }
    string getItemInfos() override {
        ostringstream itemInfos;
        itemInfos << std::left << setw(25) << m_name
                  << "| Durability: " << setw(3) << m_durability
                  << "| Defense: " << setw(3) << m_defense
                  << "| Price: " << m_price << " gold\n";
        return itemInfos.str();

    }
};

#endif //SHIELD_H