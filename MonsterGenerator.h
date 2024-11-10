//
// Created by amiar on 06/11/2024.
//

#ifndef MONSTERGENERATOR_H
#define MONSTERGENERATOR_H

#include "Zombie.h"
#include "Slime.h"
#include "Dragon.h"

class MonsterGenerator {
public:
    // Create Monster depending of the current lvl of the Mine
    static Monster* createMonster(int mineLvl) {
        int type = 0;
        if (mineLvl > 3) {type = rand() % 2;} if (mineLvl > 5) {type = rand() %3;}
        switch (type) {
            case 0: return new Slime();
            case 1: return new Zombie();
            case 2: return new Dragon();
            default: return nullptr;
        }
    }
    // Create a certain amount of Monster and add it into the given vector
    static void generateMonsters(std::vector<Monster*>& monstersList,int mineLvl, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            monstersList.push_back(createMonster(mineLvl));
        }
    }
};
#endif //MONSTERGENERATOR_H
