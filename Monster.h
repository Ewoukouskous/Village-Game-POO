//
// Created by ninol on 01/11/2024.
//

#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Hero;

using namespace std;

class Monster {
protected:
    string m_name;
    int m_health;
    int m_attack;
    int m_defense;
    int m_gold;
public:

        // GETTERS
    int getHealth() const {
        return m_health;
    }
    int getGold() const {
        return m_gold;
    }
    int getAttack() const {
        return m_attack;
    }
    string getName() const {
        return m_name;
    }
    int getDefense() const {
        return m_defense;
    }

        // SETTERS
    void setHealth(int health) {
        m_health = health;
    }

    Monster();
    virtual ~Monster();

    string showStats() const;

    // Method to attack the Hero
    void attackHero(Hero *hero);
    // Method calld when attacking the Hero to check if the Hero dodge or not
    bool isAttackDodge(Hero* hero);
    // Method to give the Hero the gold of the Monster when he kills it
    void isMonsterDead(Hero *hero, Monster *monster) const;
};

#endif //MONSTER_H
