//
// Created by ninol on 01/11/2024.
//

#include "Monster.h"
#include "Hero.h"
#include "Paladin.h"

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

void Monster::attackHero(Hero *hero) {
    const int monsterAttack = getAttack();
    int heroHealth = hero->getHealth();

    if (isAttackDodge(hero) == false) {
        int globalAttack = monsterAttack-hero->getDefense();
        if (globalAttack < 0) {
            cout << "Monster is too weak to deal you damage" << endl;
        } else {
            cout << m_name << " deal " << getAttack() << " damages to " << hero->getName() << endl;
            hero->setHealth(hero->getHealth()-globalAttack);
            if (dynamic_cast<Paladin*>(hero)) {
                auto *tempPaladin = dynamic_cast<Paladin*>(hero);
                tempPaladin->beingHit(globalAttack);
                return;
            }
            hero->beingHit(globalAttack);
        }
    }
}

bool Monster::isAttackDodge(Hero *hero) {
    // Genération d'un nombre aléatoire qui vas s'occuper du dodge
        // Initialiser la graine du générateur aléatoire
    srand(static_cast<unsigned int>(time(nullptr)));

        // Générer un nombre aléatoire entre 1 et 100
    const int randomNumber = rand() % 100 + 1;

    if (randomNumber <= hero->getDodge()) {
        cout << "You dodge this attack !" << endl;
        return true;
    }
    return false;
}
