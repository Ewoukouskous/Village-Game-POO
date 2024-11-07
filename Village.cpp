//
// Created by ninol on 06/11/2024.
//

#include "Village.h"
#include "Mine.h"
#include "Hostel.h"

Village::Village(string name) {
    m_name = name;
    Building *hostel = new Hostel();
    // Building *shop = new Building();
    Building* mine = new Mine();

    m_village.push_back(hostel);
    m_village.push_back(mine);
}

string Village::showBuilding() {
    string title = "--------- " + m_name + " ---------\n";
    string result;
    for (int i = 0; i < m_village.size(); i++) {
        if (i == m_village.size() - 1) {
            result += "|[index " + to_string(i) + "]: " + m_village[i]->getName();
        } else {
            result += "|[index " + to_string(i) + "]: " + m_village[i]->getName() + "|  ";
        }
        result +="\n";
    }
    for (int i = 0; i < title.size()-1; i++) {
        result += "-";
    }

    return title+result;
}

unsigned long Village::getVillageSize() {
    return m_village.size();
}
