//
// Created by ninol on 06/11/2024.
//

#include "Village.h"
#include "Mine.h"
#include "Hostel.h"
#include "Shop.h"

Village::Village(string name) {
    m_name = name;
    Building *hostel = new Hostel();
    Building *shop = new Shop();
    Building* mine = new Mine();

    m_village.push_back(hostel);
    m_village.push_back(shop);
    m_village.push_back(mine);
}

    // show a list of the building
string Village::showBuilding() {
    string title = "-------------- " + m_name + " ---------------\n";
    ostringstream result;
    for (int i = 0; i < m_village.size(); i++) {
        if (i < m_village.size()) {
            result << std::left <<"|[index " << to_string(i) << "]: " <<setw(28)<< m_village[i]->getName()<<"|\n";
        }
    }
    for (int i = 0; i < title.size()-1; i++) {
        result << "-";
    }
    return title+result.str();
}

unsigned long Village::getVillageSize() {
    return m_village.size();
}
