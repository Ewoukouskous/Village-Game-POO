//
// Created by ninol on 01/11/2024.
//

#ifndef SLIME_H
#define SLIME_H

#include "Monster.h"
#include "Hero.h"

class Slime : public Monster{
public:
    Slime();
    string showStats() const;
};

#endif //SLIME_H
