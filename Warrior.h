//
// Created by amiar on 23/10/2024.
//

#ifndef WARRIOR_H
#define WARRIOR_H

#include "Hero.h"

class Warrior : public Hero{
private:
public:
    Warrior(const string &name);
    // Equiper une arme (uniquement 'SWORD')
    void equipWeapon(Weapon* ptr_sword) override;
    // Equiper une SWORD provenant de l'inventaire
    void equipFromInventory(const int indexItem) override;

    // GETTERS
    const string& getType() const override {
        return m_type;
    }
};




#endif //WARRIOR.H
