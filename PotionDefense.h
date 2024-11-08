//
// Created by amiar on 01/11/2024.
//

#ifndef POTIONDEFENSE_H
#define POTIONDEFENSE_H

#include "Potion.h"

class PotionDefense : public Potion{
private:
public:
    PotionDefense(const string &name, const int &effect, const int &price);
    // Affiche un message d'utilisation et renvoie la quantité d'effect de la potion
    int use() override;
    // Renvoie 'DEFENSE_POTION'
    string getType() override {
        return m_potionType;
    }
    string getItemInfos() {
        string str = "| " + m_name + " | Effect : +" + to_string(m_effect) + "DP | Price : " + to_string(m_price) + "|";
        return str;
    }
    Item* clone() const override {
        return new PotionDefense(*this);
    }
};



#endif //POTIONDEFENSE_H
