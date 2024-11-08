//
// Created by ninol on 06/11/2024.
//

#include "Hostel.h"

Hostel::Hostel(): Building("Hostel") {}

void Hostel::sellHeal(int choice) {

    switch (choice) {
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

string Hostel::introduceBuilding() {
    string desc = "--- Welcome in the hostel, what do you want to drink ? ---\n";
    return desc;
}
