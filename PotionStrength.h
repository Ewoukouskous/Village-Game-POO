//
// Created by amiar on 01/11/2024.
//

#ifndef POTIONSTRENGTH_H
#define POTIONSTRENGTH_H

#include <iomanip>

#include "Potion.h"

class PotionStrength : public Potion {
private:
public:
    PotionStrength(const string &name, const int &effect, const int &price);
    // Display a use message and return the effect quantity of the potion
    int use() override;
    // Return 'STRENGTH_POTION'
    string getType() override {
        return m_potionType;
    }
    string getItemInfos() override {
        ostringstream itemInfos;
        itemInfos << std::left << setw(25) << m_name
                  << "| Effect: " << setw(3) << m_effect << "SP"
                  << "| Price: " <<m_price << " gold\n";
        return itemInfos.str();

    }
    Item* clone() const override {
        return new PotionStrength(*this);
    }
};

#endif //POTIONSTRENGTH_H