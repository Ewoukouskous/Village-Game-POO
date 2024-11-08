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
        m_hero->travel(hostel);m_hostel = hostel; m_title = "Hostel Menu"; m_options={"Show Stats","Drink a Half-Pint [15gold]","Drink a Pint [25gold]"};PlaySoundHostel();
;
    }
    unique_ptr<Menu> handleChoice(int choice) override {
        switch (choice) {
            case 1 :
                system("cls");
            cout << m_hero->showStats()<< endl;
            break;
            case 2 :
                system("cls");
            m_hostel->sellHeal(1);
            break;
            case 3 :
                system("cls");
            m_hostel->sellHeal(2);
            break;
            case 0:
                cout << "You leaved the Hostel" << endl;
                StopSound();
                m_hero->leave();
                break;
            default:
                cout << "Bad choice...." << endl;
        }
        return nullptr;
    }
};

#endif //HOSTELMENU_H
