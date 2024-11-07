//
// Created by ninol on 06/11/2024.
//

#include "Village.h"

#include "Hostel.h"

Village::Village(string name) {
    m_name = name;
    Building *hostel = new Hostel();
    // Building *shop = new Building();
    // Building *cave = new Building();

    m_village.push_back(hostel);
}

string Village::showBuilding() {
    string result = "--- " + m_name + " --- \n";
    for (int i = 0; i < m_village.size(); i++) {
        if (i == m_village.size() - 1) {
            result += "|[index " + to_string(i) + "]: " + m_village[i]->getName();
        } else {
            result += "|[index " + to_string(i) + "]: " + m_village[i]->getName() + "|  ";
        }
    }
    return result;
}
