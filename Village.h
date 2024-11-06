#ifndef VILLAGE_H
#define VILLAGE_H

#include <iostream>
#include <vector>
#include "Building.h"

using namespace std;

class Village {
private:
    string m_name;

    Building hostel{"hostel"};
    Building shop{"shop"};
    Building cave{"cave"};

    vector<Building> m_village;

public:

    Village(const string &name);

    void addBuildingToVector();
    string showBuildings() const;

    // GETTERS
    string getName() const {
        return m_name;
    }
    vector<Building> getBuildings() const {
        return m_village;
    }
};

#endif //VILLAGE_H
