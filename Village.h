//
// Created by ninol on 06/11/2024.
//

#ifndef VILLAGE_H
#define VILLAGE_H

#include <iostream>
#include <vector>

#include "Building.h"

using namespace std;

class Village {
private:
    string m_name;
    vector<Building*> m_village;
public:
    Village(string name);
    ~Village() {
        for (auto building : m_village) {
            delete building;
        }
    }

    string showBuilding();

    Building* getBuilding(int index) {
        return m_village[index];
    }
    string getBuildingType(int index) {return m_village[index]->getBuildingType();}
    unsigned long getVillageSize();
};

#endif //VILLAGE_H