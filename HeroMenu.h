//
// Created by amiar on 04/11/2024.
//

#ifndef HEROMENU_H
#define HEROMENU_H

#include "Warrior.h"
#include "Paladin.h"
#include "Wizard.h"
#include "Menu.h"
#include "Village.h"



// HeroMenu will display all the Hero's possible actions
// (depending on the type of Hero)
// and can call the Hero's InventoryMenu
class HeroMenu : public Menu {
private:
public:
    HeroMenu(Hero* hero);
    unique_ptr<Menu> handleChoice(int choice) override;
};



#endif //HEROMENU_H
