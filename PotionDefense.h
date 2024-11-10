//
// Created by amiar on 01/11/2024.
//

#ifndef POTIONDEFENSE_H
#define POTIONDEFENSE_H

#include <iomanip>

#include "Potion.h"

class PotionDefense : public Potion{
private:
public:
    PotionDefense(const string &name, const int &effect, const int &price);
    // Display a use message and return the effect quantity of the potion
    int use() override;
    // Return 'DEFENSE_POTION'
    string getType() override {
        return m_potionType;
    }
    string getItemInfos() override {
        ostringstream itemInfos;
        itemInfos << std::left << setw(25) << m_name
                  << "| Effect: " << setw(3) << m_effect << "DP"
                  << "| Price: " << m_price << " gold\n";
        return itemInfos.str();
    }
    Item* clone() const override {
        return new PotionDefense(*this);
    }
};



#endif //POTIONDEFENSE_H
