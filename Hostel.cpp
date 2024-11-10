//
// Created by ninol on 06/11/2024.
//

#include "Hostel.h"

Hostel::Hostel(): Building("The Drunk Shrimp Tavern") {}

    // Asks the player which drinks he want. Add health to the hero depending on the drink he choose.
void Hostel::sellHeal(int choice) {

    switch (choice) {
            // Half pint, so a bonus of 25 hp.
        case 1: {
            if (m_heroInside->getGold() >= 15) {
                if (m_heroInside->getHealth() + 25 >= 100) {
                    m_heroInside->setHealth(100);
                    m_heroInside->setGold(m_heroInside->getGold() - 15);
                    cout << "You just drinked a Half-Pint" << endl;
                    break;
                }
                m_heroInside->setHealth(m_heroInside->getHealth() + 25);
                m_heroInside->setGold(m_heroInside->getGold() - 15);
                cout << "You just drinked a Half-Pint" << endl;

                break;
            }
            cout << "You have not enough golds to purchase a half pint" << endl;
            break;
        }
            // Pint, so a bonus of 50 hp.
        case 2: {
            if (m_heroInside->getGold() >= 40) {
                if (m_heroInside->getHealth() + 50 >= 100) {
                    m_heroInside->setHealth(100);
                    m_heroInside->setGold(m_heroInside->getGold() - 40);
                    cout << "You just drinked a Pint" << endl;
                    break;
                }
                m_heroInside->setHealth(m_heroInside->getHealth() + 50);
                m_heroInside->setGold(m_heroInside->getGold() - 40);
                cout << "You just drinked a Pint" << endl;

                break;
            }
            cout << "You have not enough golds to purchase a pint" << endl;
            break;
        }
        default: {
            cout << "Please enter a valid choice" << endl;
        }
    }
}

    // Show the hero a sort of welcome message of the hostel/tavern
string Hostel::introduceBuilding() {
    string desc = "--- Welcome in the hostel, what do you want to drink ? ---\n";
    return desc;
}