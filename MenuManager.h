//
// Created by amiar on 04/11/2024.
//

#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include <stack>

#include "Menu.h"
#include "HeroMenu.h"

// MenuManager allow the user to navigate through others menu and make them display
// the different actions possibles

class MenuManager {
private:
    // currentMenu is a SmartPointer(unique) who point to a Menu class (HeroMenu for example)
    unique_ptr<Menu> currentMenu;
    stack<unique_ptr<Menu>> menuStack;
    Hero* currentHero;
public:
    MenuManager(Hero* hero){currentMenu = make_unique<HeroMenu>(hero);currentHero = hero;}
    void displayAndHandle();
};



#endif //MENUMANAGER_H
