//
// Created by amiar on 01/11/2024.
//

#include "PotionStrength.h"

PotionStrength::PotionStrength(const string &name, const int &effect, const int &price) : Potion(name,effect,price){
    m_potionType = "STRENGTH_POTION";
}

int PotionStrength::use() {
    cout << "You drink a strength potion that added " << m_effect << " to your strength" << endl;
    return m_effect;
}
