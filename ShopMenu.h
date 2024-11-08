//
// Created by amiar on 08/11/2024.
//

#ifndef SHOPMENU_H
#define SHOPMENU_H
#include "Menu.h"
#include "Shop.h"
#include "PlaySound.h"

class ShopMenu : public Menu {
private:
    Shop* m_shop = nullptr;
public:
    ShopMenu(Hero* hero, Shop* shop) : Menu(hero) {
        m_hero->travel(shop); m_shop = shop; m_title = shop->getName(); m_options = {"Check your Inventory","Show Shop Inventory","Buy Something"};PlaySoundShop();
    };

    unique_ptr<Menu> handleChoice(int choice) override {
        int index = 0;
        switch (choice) {
            case 1:
                system("cls");
                m_shop->displayAllItems();
                cout << "Your Inventory : "<< m_hero->getInventory()<<endl;
                cout << "You have " << m_hero->getGold() << " gold in your wallet" << endl;
                break;
            case 2:
                system("cls");
                m_shop->displayAllItems();
                break;
            case 3:
                system("cls");
                m_shop->displayAllItems();
                cout << "What do you want to buy ? (enter index)" <<endl;
                cin >> index; if (cin.fail()== true) {system("cls");cout << "Bad entry (not an index)\n";cin.clear(),cin.ignore(100000,'\n');break;}
                m_shop->sellItem(index);
                break;
            case 0 :
                system("cls");
                StopSound();
                cout << "You leave the Shop" << endl;
                m_hero->leave();
                m_shop = nullptr;
                break;
            default :
                cout << "Bad choice ..." << endl;
        }
        return nullptr;
    }
};

#endif //SHOPMENU_H
