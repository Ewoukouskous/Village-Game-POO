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
    // Equiper une arme (uniquement 'WAND')
    void equipWeapon(Weapon *ptr_weapon) override;
    // Equiper une WAND provenant de l'inventaire
    void equipFromInventory(const int indexItem) override;


    // GETTERS
    const string& getType() const override {
        return m_type;
    }

};


#endif //WIZARD_H
