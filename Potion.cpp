//
// Created by amiar on 29/10/2024.
//

#include "Potion.h"

Potion::Potion(const string &name, const int &effect, const int &price) :Item(name,price){
        m_potionType = "NONE";
        m_effect = effect;
}
