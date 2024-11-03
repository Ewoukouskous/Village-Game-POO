//
// Created by ninol on 03/11/2024.
//

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Monster.h"
#include "Hero.h"

class Zombie : public Monster{
public:
    Zombie();
    string showStats() const;
};


#endif //ZOMBIE_H
