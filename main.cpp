#include <algorithm>
#include <iostream>

#include "Warrior.h"
#include "Paladin.h"
#include "Wizard.h"
#include "MenuManager.h"

using namespace std;

bool isEmptyOrWhitespace(const std::string& str) {
    return str.empty() == true || ranges::all_of(str, ::isspace) == true;
}

Hero* startMenu() {
    string name;
    bool isValid = false;
    int choice = 0;
    Hero* hero = nullptr;
    cout << "Welcome to Village Game!\n------------------------" << endl;

    // Ask a name until the user provide something that's not empty or contain 'space' only
    while (isValid==false) {
        cout << "Please enter your name: "; getline(cin,name);
        if (isEmptyOrWhitespace(name) == true) {cout << "You did not enter a valid name"<<endl;continue;}
        isValid=true;
    }
    isValid=false;
    system("cls");

    cout << "Your name will be  : " << name << endl<< endl;
    while (isValid == false) {
        cout << "What type of Hero you want to be ?"<<endl;
        cout << "[1] Warrior : A Warrior does 50% more damage than the other classes"<< endl;
        cout << "[2] Paladin : A Paladin can equip a Shield to get more Defense"<< endl;
        cout << "[3] Wizard : A Wizard fight with his Wand and has 20% Chance to dodge an attack"<< endl;
        cin >> choice; if (cin.fail()==true || choice < 1 || choice > 3) {cin.clear();cin.ignore(100,'\n');system("cls");cout<<"Please enter a valid entry !"<<endl;continue;}
        switch (choice) {
            case 1:
                system("cls");
                hero = new Warrior(name);
                isValid = true;
                break;
            case 2:
                system("cls");
                hero = new Paladin(name);
                isValid = true;
                break;
            case 3:
                system("cls");
                hero = new Wizard(name);
                isValid = true;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    }
    return hero;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize a seed for the future generation of Monster
    MenuManager game (startMenu());
    game.displayAndHandle();

    return 0;
}