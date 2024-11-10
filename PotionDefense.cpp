//
// Created by amiar on 01/11/2024.
//

#include "PotionDefense.h"

PotionDefense::PotionDefense(const string &name, const int &effect, const int &price) : Potion(name,effect,price) {
    m_potionType = "DEFENSE_POTION";
}

int PotionDefense::use() {
    cout << "You drink a defense potion that added " << m_effect << " to your defense" << endl;
    return m_effect;
}