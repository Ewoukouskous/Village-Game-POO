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
};



#endif //POTIONDEFENSE_H
