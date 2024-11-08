//
// Created by amiar on 29/10/2024.
//

#ifndef POTIONHEAL_H
#define POTIONHEAL_H
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
    string getItemInfos() {
        string str = "| " + m_name + " | Effect : +" + to_string(m_effect) + "HP | Price : " + to_string(m_price) + "|";
        return str;
    }

    Item* clone() const override {
        return new PotionHeal(*this);
    }
    
};



#endif //POTIONHEAL_H
