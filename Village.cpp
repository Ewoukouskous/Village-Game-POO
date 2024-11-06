#include "Village.h"

Village::Village(const string &name) : m_name(name) {
    addBuildingToVector();
}

void Village::addBuildingToVector() {
    // Ajouter directement les objets au vecteur
    m_village.push_back(hostel);
    m_village.push_back(shop);
    m_village.push_back(cave);
}

string Village::showBuildings() const {
    string names;
    cout << "                  --- " << getName() << " ---" << endl;
    for (int i = 0; i < m_village.size(); i++) {
        if (i == m_village.size() - 1) {
            names += "|[index " + to_string(i) + "]: " + m_village[i].getName() ;
        } else {
            names += "|[index " + to_string(i) + "]: " + m_village[i].getName() + " | ";
        }
    }
    return names;
}
