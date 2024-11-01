//
// Created by amiar on 29/10/2024.
//

#include "PotionHeal.h"

PotionHeal::PotionHeal(const string &name, const int &effect, const int &price) : Potion(name, effect, price) {
    m_potionType = "HEAL_POTION";
}

int PotionHeal::use() {
    cout << "You drink a heal potion that provide you " << getEffect() << " HP" << endl;
    return m_effect;
}

