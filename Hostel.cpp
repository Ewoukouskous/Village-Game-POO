//
// Created by ninol on 06/11/2024.
//

#include "Hostel.h"

Hostel::Hostel(): Building("Hostel") {}

void Hostel::sellHeal(int choice, Hero *hero) {

    switch (choice) {
        case 1: {
            if (hero->getGold() >= 15) {
                if (hero->getHealth() + 25 >= 100) {
                    hero->setHealth(100);
                    hero->setGold(hero->getGold() - 15);
                    break;
                }
                hero->setHealth(hero->getHealth() + 25);
                hero->setGold(hero->getGold() - 15);
                break;
            }
            cout << "You have not enough golds to purchase a half pint" << endl;
        }
        case 2: {
            if (hero->getGold() >= 25) {
                if (hero->getHealth() + 50 >= 100) {
                    hero->setHealth(100);
                    hero->setGold(hero->getGold() - 25);
                    break;
                }
                hero->setHealth(hero->getHealth() + 50);
                hero->setGold(hero->getGold() - 25);
                break;
            }
            cout << "You have not enough golds to purchase a pint" << endl;
        }
        default: {
            cout << "Please enter a valid choice" << endl;
        }
    }
}

string Hostel::introduceBuilding() {
    string desc = "--- Welcome in the hostel, what do you want to drink ? ---";
    return desc;
}
