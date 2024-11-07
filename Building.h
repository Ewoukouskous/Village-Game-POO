//
// Created by ninol on 06/11/2024.
//

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

#include "Hero.h"

class Hero;

using namespace std;

class Building {
protected:
    string m_name;
    Hero *m_heroInside = nullptr;
public:
    Building(string name);

    virtual string introduceBuilding() = 0;

        //GETTERS
    string getName() {
        return m_name;
    }
    Hero* getHeroInside() const {
        return m_heroInside;
    }
    virtual string getBuildingType() =0;

    Building* getBuilding() {
        return this;
    }

        //SETTERS
    void setHeroInside(Hero *heroInside) {
        m_heroInside = heroInside;
    }
};



#endif //BUILDING_H
