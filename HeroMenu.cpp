//
// Created by amiar on 04/11/2024.
//

#include "HeroMenu.h"

#include "InventoryMenu.h"
// It will display this title :
// ---|Hero's name| the |Hero's type|---
// ---Bob the Paladin---
HeroMenu::HeroMenu(Hero* hero): Menu(hero) {
    m_title = hero->getName() + " the " + hero->getType();
    m_options = hero->getBasicActions();
}

unique_ptr<Menu> HeroMenu::handleChoice(int choice) {
        switch (choice) {
            case 1: // Introduce Yourself
                system("cls");
            m_hero->introduceHimself();
            break;
            case 2: // Inventory Menu
                system("cls");
            // return the InventoryMenu pointer so MenuManager can change the current menu
                return make_unique<InventoryMenu>(m_hero);
            case 3: // Travel
                system("cls");
            cout << "WIP : Travel" << endl;
            break;
            case 4: // Show Stats
                system("cls");
            cout << m_hero->showStats() << endl;
            break;
            case 0 :
                system("cls");
                cout << "You can't backward in this menu" << endl;
                break;
            default:
                cout << "Bad Choice ..." << endl;
            break;
        }
    // If no sub-menu action is selected it will return a nullptr
    // so the menuManager don't change the current Menu
    return nullptr;
    }

