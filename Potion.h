//
// Created by amiar on 29/10/2024.
//

#ifndef POTION_H
#define POTION_H

#include "Item.h"


class Potion : public Item{
protected:
    string m_potionType; // Type de potion
    int m_effect; // Quantité d'effet
public:
    Potion(const string &name, const int &effect, const int &price);

    // GETTERS
    int getEffect() const {
        return m_effect;
    }
};



#endif //POTION_H
