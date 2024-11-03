//
// Created by amiar on 01/11/2024.
//

#ifndef POTIONSTRENGTH_H
#define POTIONSTRENGTH_H
#include "Potion.h"


class PotionStrength : public Potion {
private:
public:
    PotionStrength(const string &name, const int &effect, const int &price);
    // Affiche un message d'utilisation et renvoie la quantité d'effect de la potion
    int use() override;
    // Renvoie 'STRENGTH_POTION'
    string getType() override {
        return m_potionType;
    }
};



#endif //POTIONSTRENGTH_H
