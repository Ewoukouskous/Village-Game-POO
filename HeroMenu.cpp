//
// Created by amiar on 04/11/2024.
//

#include "HeroMenu.h"

#include "Hostel.h"
#include "HostelMenu.h"
#include "InventoryMenu.h"
#include "Mine.h"

// It will display this title :
// ---|Hero's name| the |Hero's type|---
// ---Bob the Paladin---
HeroMenu::HeroMenu(Hero* hero): Menu(hero) {
    m_title = hero->getName() + " the " + hero->getType();
    m_options = hero->getBasicActions();
}

unique_ptr<Menu> HeroMenu::handleChoice(int choice) {
        int index = 0;

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
                // Ask where the Hero want to travel and display all the possible destination
                cout << "Where do you want to travel ?" << endl;
                cout << m_hero->getHeroVillage()->showBuilding()<<endl;
                cin >> index;
                // If the given index is wrong we stop the case 3 'Travel' and ask a valid entry
                if (cin.fail() == true || index < 0 || index >= m_hero->getHeroVillage()->getVillageSize()) {cin.clear();cin.ignore(10000,'\n');cout << "Please enter a valid entry" <<endl;break;}
                // If the given index refer to a building type 'Hostel' we return the HostelMenu
                if (m_hero->getHeroVillage()->getBuildingType(index) == "Hostel") {
                    system("cls");;
                    return make_unique<HostelMenu>(m_hero,dynamic_cast<Hostel*>(m_hero->getHeroVillage()->getBuilding(index)));
                }
                // Else if the given index refer to a building type 'Mine' we call the startFight() method of the 'Mine'
                else if (m_hero->getHeroVillage()->getBuildingType(index) == "Mine"){
                    system("cls");
                    m_hero->travel(m_hero->getHeroVillage()->getBuilding(index));
                    dynamic_cast<Mine*>(m_hero->getHeroVillage()->getBuilding(index))->startFight();
                    }
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

