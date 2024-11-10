//
// Created by amiar on 07/11/2024.
//

#ifndef MINE_H
#define MINE_H

#include "Building.h"
#include "Monster.h"
#include "PlaySound.h"

class Mine : public Building {
private :
    int m_mineLvl;
    vector <Monster*> m_monstersList;
    int m_fibonacci(int mineLvl){
        if (mineLvl <= 1) return mineLvl;
        return m_fibonacci(mineLvl - 1) + m_fibonacci(mineLvl - 2);
    }
public:
    Mine(): Building("The 'Paraceta'mole' Cave"),m_mineLvl(1){}
    ~Mine() {
        for (auto monster : m_monstersList) {
            delete monster;
        }
    }

    string introduceBuilding() override;

    void startFight();


    void showMonsters() {
        cout << "| ";
        for (auto &monster : m_monstersList) {
            cout<< monster->getName() << " | ";
        }
        cout <<endl;
    }

    string mineStatus();

    string getBuildingType() override;
};

#endif //MINE_H