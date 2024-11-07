//
// Created by amiar on 06/11/2024.
//

#ifndef FIGHTMENU_H
#define FIGHTMENU_H

#include "Menu.h"
#include "InventoryMenu.h"

// FightMenu allow the user to see his stats, go to his inventory and attack
class FightMenu : public Menu {
public:
    FightMenu(Hero* hero): Menu(hero) {m_title = "FightMenu"; m_options ={"Hero Infos","Inventory","Attack Monster"};}
    unique_ptr<Menu> handleChoice(int choice) override{
            switch (choice) {
                case 1: // Hero Infos
                    cout << m_hero->showStats()<<endl;
                    break;
                case 2: // Inventory
                    system("cls");
                    return make_unique<InventoryMenu>(m_hero);
                case 3: // Attack Monster
                    system("cls");
                break;
                case 0: // Return backward (not possible in a fight)
                    system("cls");
                    cout << "You can't leave from a fight ;) " << endl;
                    break;
                default:
                    cout << "Bad choice..." << endl;
            }
            return nullptr;
        }

};

#endif //FIGHTMENU_H
