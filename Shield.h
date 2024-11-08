//
// Created by amiar on 25/10/2024.
//

#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield : public Item{
private:
    string m_itemType; // = SHIELD
    int m_defense;
    int m_durability;
public:
    Shield(const int &defense, const int &durability, const string &name, const int &price);
    // Renvoi le type 'SHIELD'
    string getType () override;
    // Appelée lorsque un joueur l'utilise (baisse sa durabilité et renvoie la qte de defense)
    int use() override;
    // Une fois la durabilité a 0 le bouclier casse et ne protège plus
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
    string getItemInfos() {
        string str = "| " + m_name + " | Defense : " + to_string(m_defense) + " | Durability : " + to_string(m_durability) + " | Price : " + to_string(m_price) + "|";
        return str;
    }
};



#endif //SHIELD_H
