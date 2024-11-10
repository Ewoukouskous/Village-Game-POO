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
    // Equipe a Weapon ('SWORD' only)
    void equipWeapon(Weapon* ptr_sword) override;
    // Equip a SWORD from his Inventory
    void equipFromInventory(int indexItem) override;

    // GETTERS
    const string& getType() const override {
        return m_type;
    }
};

#endif //WARRIOR.H