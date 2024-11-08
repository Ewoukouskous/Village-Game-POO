//
// Created by amiar on 23/10/2024.
//

#ifndef WAND_H
#define WAND_H

#include "Weapon.h"

class Wand : public Weapon {
public:
    Wand(const int &damage,const int &durability, const string &name, const int &price);
    // Renvoi le type d'arme (WAND)
    string getType () override;
    // Appelée lorsque un joueur l'utilise (baisse sa durabilité et renvoie la qte de damage)
    int use () override;
    // Une fois la durabilité a 0 l'arme casse et ne fait plus de dégats
    void weaponBreak() override;

    Item* clone() const override {
        return new Wand(*this);
    }

};



#endif //WAND_H
