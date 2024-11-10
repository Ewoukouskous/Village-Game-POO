//
// Created by amiar on 04/11/2024.
//

#include "MenuManager.h"

#include <limits>

// MenuManager allow the user to navigate through others menu and make them display
// the different actions possibles

// displayAndHandle() display the possible action of the current menu and will ask
// to the user to enter a choice
// and if the choice return to a sub-Menu the current menu will change
void MenuManager::displayAndHandle() {
    int choice;
    while (currentHero->getHealth()>0) {
        currentMenu->display();
        cin >> choice;
        // Check if the user enter a valid action (if he enter a letter it will ask him to ask valid entry
        // and same if he enter input less than 0 or more than the possible actions)
        if (cin.fail() || choice < 0 || choice > currentMenu->getOptionsSize()) {
            cin.clear(); // reinit the error status
            cin.ignore(10000,'\n'); // Ignore the incorrect entry
            system("cls");
            cout << "Please enter a valid action" << endl;
            continue; // Restart the loop for ask a new entry
        }

        // handleChoice will return a sub-menu pointer or a nullptr
        unique_ptr<Menu> newMenu = currentMenu->handleChoice(choice);
        // if handleChoice return anything else than a nullptr the currentMenu
        // will be pushed at the top of MenuStack and currentMenu will become the corresponding
        // sub-menu.
        if (newMenu != nullptr) {
            menuStack.push(move(currentMenu));
            currentMenu = move(newMenu);
        }
        // If the user enter '0' (and the stack isn't empty) the currentMenu will become the
        // menu in top of the menuStack, and then we delete the menu from the stack because
        // we transfered it to currentMenu
        else if (choice == 0 && !menuStack.empty()) {
            currentMenu = move(menuStack.top());
            menuStack.pop();
        }
    }
    system("cls");
    cout<< "You just died :( \nGAME OVER !!!!" << endl;
    system("pause");
}