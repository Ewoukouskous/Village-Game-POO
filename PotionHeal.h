//
// Created by amiar on 29/10/2024.
//

#ifndef POTIONHEAL_H
#define POTIONHEAL_H
#include <iomanip>

#include "Potion.h"


class PotionHeal : public Potion{
private:
public:
    PotionHeal(const string &name, const int &effect, const int &price);
    // Affiche un message d'utilisation et renvoie la quantité d'effect de la potion
    int use() override;
    // Renvoie 'HEAL_POTION'
    string getType() override {
        return m_potionType;
    }
    string getItemInfos() override {
        ostringstream itemInfos;
        itemInfos << std::left << setw(25) << m_name
                  << "| Effect: " << setw(3) << m_effect << " HP"
                  << "| Price: " << m_price << " gold\n";
        return itemInfos.str();
    }

    Item* clone() const override {
        return new PotionHeal(*this);
    }
    
};



#endif //POTIONHEAL_H
