//
// Created by amiar on 06/11/2024.
//

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include <stack>

#include "FightMenu.h"
#include "Menu.h"

// FightManager is pretty much like MenuManager class but this one is specialized for the turn based fight
// he contain a 'while the user don't press 3' loop unlike the MenuManager
// who use a 'while the Hero's not dead' loop.
class FightManager {
private:
    unique_ptr<Menu> currentMenu;
    stack<unique_ptr<Menu>> menuStack;
public:

    // FightManager will start the FightMenu Menu
    FightManager(Hero* hero){currentMenu = make_unique<FightMenu>(hero);}

    // displayAndHandle() display the possible action of the current menu and will ask
    // to the user to enter a choice
    // and if the choice return to a sub-Menu the current menu will change
    int displayAndHandle(Hero* hero) {
    int choice;
    while (choice !=3 || !menuStack.empty()) {
        currentMenu->display();
        cin >> choice;
        // Check if the user enter a valid action (if he enter a letter it will ask him to ask valid entry
        // and same if he enter input less than 0 or more than the possible actions)
        if (cin.fail() || choice < 0 || choice > currentMenu->getOptionsSize()) {
            cin.clear(); // Reinitialize the cin error state
            cin.ignore(10000,'\n'); // ignore all the incorrect entry
            system("cls");
            cout << "Please enter a valid action" << endl;
            continue; // Restart the loop
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
        // menu in top of the menuStack and then we delete the menu from the stack because
        // we transfered it to currentMenu
        else if (choice == 0 && !menuStack.empty()) {
            currentMenu = move(menuStack.top());
            menuStack.pop();
        }
    }   // We return 3 so the turn based combat can continue
        return 3;
}
};

#endif //FIGHTMANAGER_H