//
// Created by amiar on 29/10/2024.
//

#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item{
protected:
    string m_potionType; // The Potion Type
    int m_effect; // Quantity of effect
public:
    Potion(const string &name, const int &effect, const int &price);

    // GETTERS
    int getEffect() const {
        return m_effect;
    }
};

#endif //POTION_H