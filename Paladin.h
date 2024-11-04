//
// Created by amiar on 25/10/2024.
//

#ifndef PALADIN_H
#define PALADIN_H

#include "Hero.h"

class Paladin : public Hero {
private:
    Shield* m_shield = nullptr; // Paladin a la possibilité d'équiper un SHIELD
public:
    Paladin(const string &name);
    ~Paladin() {delete m_shield;};
    // Equiper une arme (uniquement 'SWORD')
    void equipWeapon(Weapon* ptr_sword) override;
    // Equiper un SHIELD
    void equipShield(Shield* ptr_shield);
    // Range l'arme dans l'inventaire et la désequippe (si il reste de la place)
    void storeShield();
    // Supprime et DETRUIT le SHIELD équipé par le hero
    void dropShield();
    // Equiper un SHIELD ou une SWORD provenant de l'inventaire
    void equipFromInventory(const int indexItem) override;

    string showStats() const override;

    // GETTERS
    int getDefense() const override {
        // La défense dépendra du SHIELD équipé
        int defense = m_defense;
        if (m_shield != nullptr) {
            defense += m_shield->getDefense();
        }
        return defense;
    }

    const string& getType() const override {
        return m_type;
    }

};



#endif //PALADIN_H
