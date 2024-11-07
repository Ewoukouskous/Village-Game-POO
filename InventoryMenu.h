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
    InventoryMenu(Hero* hero) : Menu(hero)
        {m_title = m_hero->getName() + "'s Inventory";
        m_options = m_hero->getInventoryActions();}



    unique_ptr<Menu> handleChoice(int choice) override {
        int index = 0;
        if (dynamic_cast<Paladin*>(m_hero)) {
            Paladin* paladin = dynamic_cast<Paladin*>(m_hero);
            switch (choice) {
                case 1: // Show Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    break;
                case 2: // Remove from Inventory
                    system ("cls");
                    // cout << "WIP : Remove from Inventory" << endl;
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the item you want to delete" << endl;
                    cin >> index;
                    if (!cin.fail()) {
                    m_hero->removeFromInventory(index);
                    }
                break;
                    break;
                case 3: // Store current weapon
                    system ("cls");
                    m_hero->storeWeapon();
                    break;
                case 4: // Store current shield
                    system ("cls");
                    paladin->storeShield();
                    break;
                case 5: // Equip From Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the Weapon you want to equip" << endl;
                    cin >> index;
                    m_hero->equipFromInventory(index);
                    break;
                case 6: // Drink From Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the Potion you want to drink" << endl;
                    cin >> index;
                    m_hero->drinkFromInventory(index);
                    break;
                case 0 : // Return to the Hero's Menu
                    system ("cls");
                    // return make_unique<HeroMenu>(m_hero);
                    break;
                default :
                    cout << "Bad choice .... " <<endl;
            }
        }
        else {
            switch (choice) {
                case 1: // Show Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    break;
                case 2: // Remove from Inventory
                    system ("cls");
                    // cout << "WIP : Remove from Inventory" << endl;
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the item you want to delete" << endl;
                    cin >> index;
                    if (!cin.fail()) {
                    m_hero->removeFromInventory(index);
                    }
                    break;
                case 3: // Store current weapon
                    system ("cls");
                    m_hero->storeWeapon();
                    break;
                case 4: // Equip From Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the Weapon you want to equip" << endl;
                    cin >> index;
                    m_hero->equipFromInventory(index);
                    break;
                case 5: // Remove From Inventory
                    system ("cls");
                    cout << m_hero->getInventory() << endl;
                    cout << "Please enter the index of the Potion you want to drink" << endl;
                    cin >> index;
                    m_hero->drinkFromInventory(index);
                    break;
                case 0 : // Return to the Hero's Menu
                    system ("cls");
                    // return make_unique<HeroMenu>(m_hero);
                default :
                    cout << "Bad choice .... " <<endl;

            }
        }
        return nullptr;
    }
};


#endif //INVENTORYMENU_H
