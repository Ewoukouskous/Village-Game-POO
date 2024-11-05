//
// Created by amiar on 04/11/2024.
//

#ifndef MENU_H
#define MENU_H

#include <memory>
#include <string>
#include <vector>
#include "Hero.h"

using namespace std;

// Menu is the parent class of all the Menu present in the game
// All Menus will be able to display all their possible actions
// and handle a choice from the user
// It will need to receive a pointer of Hero
class Menu {
protected:
    string m_title;
    Hero* m_hero;
    vector <string> m_options;
public:
    Menu(Hero* hero) {m_hero = hero;};

    virtual void display();
    virtual unique_ptr<Menu> handleChoice(int choice) = 0;
    unsigned long getOptionsSize() const {
        return m_options.size();
    }
};



#endif //MENU_H
