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

    // juste pour voir les stats du monstre pour le debug
    virtual string showStats() const;

    // Méthode qui s'occupe d'attaquer le Hero
    void attackHero(Hero *hero);
    // Méthode appelée lors de l'attaque du Hero qui vérifie si le Hero dodge ou non
    bool isAttackDodge(Hero* hero);
    // Méthode qui va give les gold au Hero si le monstre est mort
    void isMonsterDead(Hero *hero, Monster *monster) const;
};

#endif //MONSTER_H
