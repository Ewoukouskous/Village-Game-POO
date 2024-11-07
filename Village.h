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

    string showBuilding();

    Building* getBuilding(int index) {
        return m_village[index];
    }
};

#endif //VILLAGE_H
