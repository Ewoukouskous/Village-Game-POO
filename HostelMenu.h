//
// Created by amiar on 07/11/2024.
//

#ifndef HOSTELMENU_H
#define HOSTELMENU_H

#include "Hostel.h"
#include "Menu.h"
#include "PlaySound.h"

class HostelMenu : public Menu {
private: Hostel* m_hostel = nullptr;
public:
    HostelMenu(Hero* hero, Hostel* hostel) : Menu(hero) {
        m_hero->travel(hostel);m_hostel = hostel; m_title = hostel->getName(); m_options={"Show Hero Stats","Drink a Half-Pint (+25HP) [15golds]","Drink a Pint (+50HP) [40golds]"};PlaySoundHostel();
    }
    unique_ptr<Menu> handleChoice(int choice) override {
        switch (choice) {
            case 1 : // Show Hero Stats
                system("cls");
                cout << m_hero->showStats()<< endl;
                break;
            case 2 : // Drink a Half-Pint
                system("cls");
                 m_hostel->sellHeal(1);
                break;
            case 3 : // Drink a Pint
                system("cls");
                m_hostel->sellHeal(2);
                break;
            case 0: // Leave the Hostel
                cout << "You leaved the "<< m_hostel->getName() << endl;
                StopSound();
                m_hero->leave();
                m_hostel = nullptr;
                system("cls");
                break;
            default:
                cout << "Bad choice...." << endl;
        }
        return nullptr;
    }
};

#endif //HOSTELMENU_H