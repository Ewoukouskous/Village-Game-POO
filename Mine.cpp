//
// Created by amiar on 07/11/2024.
//

#include "Mine.h"
#include "MonsterGenerator.h"
#include "FightManager.h"

string Mine::introduceBuilding() {
    string str = "";
    str = "You just entered in a dark mine .... \n";
    return str;
}

string Mine::mineStatus() {
    string str = "Monsters lefts : " + to_string(m_monstersList.size()) + "\nCurrent Monster: |" + m_monstersList[0]->
                 showStats();
    return str;
}


void Mine::startFight() {
    // Determinate the qty of monster from fibonacci and generate them
    int monsterQty = m_fibonacci(m_mineLvl);
    MonsterGenerator::generateMonsters(m_monstersList,m_mineLvl,monsterQty);
    // Initialize the FightMenu
    FightManager fightManager(m_heroInside);
    // Display all the monsters the hero have to fight
    cout << "Mine level: " << m_mineLvl << endl;
    showMonsters();

    PlaySoundCave();
    // The turn based fight loop.
    // It will loop until all the monsters aren't dead
    while (!m_monstersList.empty()) {
        // If at the start of the loop the first monster is dead we erase it from the list
        if (m_monstersList[0]->getHealth()<=0) {
            m_monstersList.erase(m_monstersList.begin());
            continue;
        }
        cout << mineStatus()<<endl;

        // If the hero have a weapon equipped it will display it
        // and if the hero is a paladin who have a shield equipped it will display it too
        if (m_heroInside->getWeapon()!=nullptr) {cout << "Equipped Weapon : " << m_heroInside->getWeaponName()<<endl;}
        if (dynamic_cast<Paladin*>(m_heroInside)) {
            Paladin* tempPaladin = dynamic_cast<Paladin*>(m_heroInside);
            if (tempPaladin->getShield()!=nullptr) {
                cout << "Equipped Shield : " << tempPaladin->getShieldName()<<endl;
            }
        }



        // It the turn of the Hero, we start his fight menu (where he can go through his inventory)
        // Until he press '3' the Hero don't attack the Monster
        if(fightManager.displayAndHandle(m_heroInside)==3) {
            system("cls");
            m_heroInside->attackMonster(m_monstersList[0]);
            cout << " - - - - - - - - - - - - - - -" << endl;
            // if the Monster don't die he will automatically attack the Hero
            if (m_monstersList[0]->getHealth()<=0) {continue;}

            m_monstersList[0]->attackHero(m_heroInside);
            cout << " - - - - - - - - - - - - - - -" << endl;
            if (m_heroInside->getHealth() <=0) {return;}

        }
    }
    // When there is no more Monsters in the Mine we increase the mine level and make the Hero leave.
    system("cls");
    m_mineLvl++;
    cout << "Congrats!!!! You killed all the monster of that cave ! "<<endl;
    cout << "The next mine level will be " << m_mineLvl << endl;
    StopSound();
    PlaySoundCongratsSFX();
    m_heroInside->leave();
}

string Mine::getBuildingType() {
    return "Mine";
}

