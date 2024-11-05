//
// Created by ninol on 03/11/2024.
//

#ifndef DRAGON_H
#define DRAGON_H

#include "Monster.h"
#include "Hero.h"

class Dragon : public Monster{
public:
    Dragon();
    string showStats() const;
};


#endif //DRAGON_H
