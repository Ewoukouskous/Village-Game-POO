//
// Created by amiar on 04/11/2024.
//

#ifndef INVENTORYMENU_H
#define INVENTORYMENU_H

#include "Menu.h"

class InventoryMenu : public Menu{
public:
    // Display example :
    // ---Bob's Inventory---
    // 1. Show Inventory
    // 2. Add To Inventory
    // 3. Remove From Inventory
    // etc...
    // lastOne. Return to the hero's menu
    InventoryMenu(Hero* hero) : Menu(hero)
        {m_title = m_hero->getName() + "'s Inventory";
        m_options = m_hero->getInventoryActions();
        m_options.push_back("Return to the Hero's Menu");}



    unique_ptr<Menu> handleChoice(int choice) override {
        int index = 0;
        switch (choice) {
            case 1: // Show Inventory
                system ("cls");
                cout << m_hero->getInventory() << endl;
                break;
            case 2: // Add to Inventory
                system ("cls");
                cout << "WIP : Add to Inventory" << endl;
                break;
            case 3: // Remove from Inventory
                system ("cls");
                cout << "WIP : Remove from Inventory" << endl;
                break;
            case 4:
                system ("cls");
                m_hero->storeWeapon();
                break;
            case 5: // Equip From Inventory
                system ("cls");
                cout << m_hero->getInventory() << endl;
                cout << "Please enter the index of the Weapon you want to equip" << endl;
                cin >> index;
                m_hero->equipFromInventory(index);
                break;
            case 6: // Remove From Inventory
                system ("cls");
                cout << m_hero->getInventory() << endl;
                cout << "Please enter the index of the Potion you want to drink" << endl;
                cin >> index;
                m_hero->drinkFromInventory(index);
                break;
            case 7 : // Return to the Hero's Menu
                system ("cls");
                return make_unique<HeroMenu>(m_hero);
            default :
                cout << "Bad choice .... " <<endl;

        }
        return nullptr;
    }
};


#endif //INVENTORYMENU_H
