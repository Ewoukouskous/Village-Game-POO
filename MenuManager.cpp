//
// Created by amiar on 04/11/2024.
//

#include "MenuManager.h"
// MenuManager allow the user to navigate through others menu and make them display
// the different actions possibles

// displayAndHandle() display the possible action of the current menu and will ask
// to the user to enter a choice
// and if the choice return to a sub-Menu the current menu will change
void MenuManager::displayAndHandle() {
    int choice;
    while (true) {
        currentMenu->display();
        cin >> choice;

        // handleChoice will return a sub-menu pointer or a nullptr
        unique_ptr<Menu> newMenu = currentMenu->handleChoice(choice);
        // if handleChoice return anything else than a nullptr the currentMenu
        // will be the correspondant sub-Menu
        if (newMenu != nullptr) {
            currentMenu = move(newMenu);
        }
    }
}
