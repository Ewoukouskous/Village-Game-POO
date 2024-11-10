//
// Created by amiar on 23/10/2024.
//

#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"


class Sword : public Weapon {
public:
    Sword(const int &damage,const int &durability, const string &name, const int &price);
    // Return the type of Weapon (SWORD)
    string getType () override;
    // Called when the Hero use it (decrement it's durability and return the quantity of damage)
    int use () override;
    // When the durability reach 0 the Weapon break and don't deal damage anymore
    void weaponBreak() override;

    Item* clone() const override {
        return new Sword(*this);
    }
};



#endif //SWORD_H
