//
// Created by amiar on 25/10/2024.
//

#ifndef PALADIN_H
#define PALADIN_H

#include "Hero.h"
#include "Monster.h"

class Paladin : public Hero {
private:
    Shield* m_shield = nullptr; // Paladin has the possibility to equip a SHIELD
public:
    Paladin(const string &name);
    ~Paladin() {delete m_shield;};
    // Equip a Weapon ('SWORD only)
    void equipWeapon(Weapon* ptr_sword) override;
    // Equip a 'SHIELD'
    void equipShield(Shield* ptr_shield);
    // Store the Weapon in the Inventory and unequip it (if there is room left)
    void storeShield();
    // Delete and DESTROY the Shield equipped by the Hero
    void dropShield();
    // Equip a SHIELD or a SWORD from the Inventory
    void equipFromInventory(const int indexItem) override;

    void drinkFromInventory(const int indexItem) override;

    string showStats() const override;

    // Contain all the Inventory related actions
    vector<string> getInventoryActions() const override;

    virtual void beingHit(int mobAttack) const;

    // GETTERS
    int getDefense() const override {
        // The defense depend of the SHIELD equipped
        int defense = m_defense;
        if (m_shield != nullptr) {
            defense += m_shield->getDefense();
        }
        return defense;
    }

    const string getShieldName() const {
        if (m_shield == nullptr) {
            return "NULL Shield";
        }
        return m_shield->getName();
    }

    Shield* getShield() const {
        return m_shield;
    }

    const string& getType() const override {
        return m_type;
    }

};



#endif //PALADIN_H
