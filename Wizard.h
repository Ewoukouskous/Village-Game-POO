//
// Created by amiar on 23/10/2024.
//

#ifndef WIZARD_H
#define WIZARD_H

#include "Hero.h"

class Wizard : public Hero{
private:
public:
    Wizard(const string &name);
    // Equip a Weapon ('WAND' only)
    void equipWeapon(Weapon *ptr_weapon) override;
    // Equip a  WAND from his Inventory
    void equipFromInventory(const int indexItem) override;


    // GETTERS
    const string& getType() const override {
        return m_type;
    }

};


#endif //WIZARD_H
