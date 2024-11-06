//
// Created by amiar on 06/11/2024.
//

#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include <string>
#include "Zombie.h"
#include "Slime.h"
#include "Dragon.h"


using namespace std;
class MonsterGenerator {
public:
    static Monster* createMonster(int mineLevel) {
        int type = 0;
        if (mineLevel < 5 ) {
            type = rand() % 2;
        } else {
            type = rand() % 3;
        }
        switch (type) {
            case 0: return new Slime();
            case 1: return new Zombie();
            case 2: return new Dragon();
            default : return nullptr;
        }
    }

    static void generateMonsters(vector<Monster*>& monstersList, int minelevel , int monsterQty) {
        for (int i = 0; i < monsterQty; i++) {
            monstersList.push_back(createMonster(minelevel));
        }
    }
};

#endif //MONSTERGENERATOR_H
