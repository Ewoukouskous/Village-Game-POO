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
    static Monster* createMonster(int mineLvl) {
        int type = 0;
        if (mineLvl <5) {type = rand() % 2;} else {type = rand() %3;}
        switch (type) {
            case 0: return new Slime();
            case 1: return new Zombie();
            case 2: return new Dragon();
            default: return nullptr;
        }
    }

    static void generateMonsters(std::vector<Monster*>& monstersList,int mineLvl, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            monstersList.push_back(createMonster(mineLvl));
        }
    }
};
#endif //MONSTERGENERATOR_H
