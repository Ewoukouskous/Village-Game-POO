//
// Created by ninol on 01/11/2024.
//

#include "Monster.h"

Monster::Monster() {
    m_name = "";
    m_health = 0;
    m_attack = 0;
    m_defense = 0;
    m_gold = 0;
}

Monster::~Monster() {

}

string Monster::showStats() const {
    string str = "Type : " + m_name + "\n"
    + "Health: " + to_string(m_health) + "\n"
    + "Attack : " + to_string(m_attack) + "\n"
    + "Defense : " + to_string(m_defense) + "\n"
    + "Gold : " + to_string(m_gold) + "\n";

    return str;
}

void Monster::attackHero(Hero *hero, Monster *monster) const {
    const int monsterAttack = m_attack;
    int heroHealth = hero->getHealth();

    if (isAttackDodge(hero) == false) {
        heroHealth -= monsterAttack;
        if (heroHealth <= 0) {
            cout << "Hero is dead" << endl; // Remplacer par gameOver
        }
    }
    hero->setHealth(heroHealth);
}

bool Monster::isAttackDodge(const Hero *hero) {
    // Genération d'un nombre aléatoire qui vas s'occuper du dodge
        // Initialiser la graine du générateur aléatoire
    srand(static_cast<unsigned int>(time(nullptr)));

        // Générer un nombre aléatoire entre 1 et 100
    const int randomNumber = rand() % 100 + 1;
    cout << "Random number : " << randomNumber << endl;

    if (randomNumber <= hero->getDodge()) {
        return true;
    }
    return false;
}

void Monster::isMonsterDead(Hero *hero, Monster *monster) const {
    if (m_health < 0) {
        cout << "Monster is dead" << endl;
        hero->setGold(m_gold);
        ~Monster(monster);
    }
}
