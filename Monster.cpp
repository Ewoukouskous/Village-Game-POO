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

    // show stats of the monster
string Monster::showStats() const {
    string str = "Type : " + m_name + " | "
    + "Health: " + to_string(m_health) + " | "
    + "Attack : " + to_string(m_attack) + " | "
    + "Defense : " + to_string(m_defense) + " | "
    + "Gold : " + to_string(m_gold) + " |\n";

    return str;
}

    // Function called when the monsters needs to deal damages to the hero
void Monster::attackHero(Hero *hero) {
    const int monsterAttack = getAttack();

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

    // If the hero is a wizard, he can dodge. This function generate a random number who check if the hero can dodge or no
bool Monster::isAttackDodge(Hero *hero) {
    // Generation of a random number between 1 to 100
        // Init the see dof the random generator
    srand(static_cast<unsigned int>(time(nullptr)));

        // Générer un nombre aléatoire entre 1 et 100
    const int randomNumber = rand() % 100 + 1;

    if (randomNumber <= hero->getDodge()) {
        cout << "You dodge this attack !" << endl;
        return true;
    }
    return false;
}
