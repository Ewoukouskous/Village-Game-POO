//
// Created by amiar on 24/10/2024.
//

#include "Inventory.h"

// Constructeur
Inventory::Inventory() {
    // Taille par défaut de l'inventaire = 10
    m_sizeMax = 10;
}

// Destructeur
Inventory::~Inventory() {
    // Detruit les items de l'inventaire 1 à 1 tant qu'il n'est pas vide (en partant de la fin)
    while (!m_itemsArray.empty()) {
        delete m_itemsArray.back(); // Supprime l'élément en fin de vecteur
        m_itemsArray.pop_back();    // Supprime le pointeur de la liste
    }
}


// Ajoute un pointeur d'item dans 'm_itemsArray'
void Inventory::addItem(Item* ptr_item) {
    // Si l'inventaire est remplis (10 items) = erreur
    if (m_itemsArray.size() >= m_sizeMax) {
        cout << "Your inventory is full, you can't add anything in it" << endl;
        return;
    }
    // Sinon on l'ajoute au bout de la liste
    m_itemsArray.push_back(ptr_item);
}

// Retire un pointeur d'item dans 'm_itemsArray' et le détruit.
void Inventory::removeItem(const int indexItem) {
    // Si l'index fourni correspond a aucun item présent dans l'inventaire on renvoie une erreur
    if (indexItem < 0 || indexItem >= m_itemsArray.size()) {
        cout << "The item that you want to remove is inexistant" << endl;
        return;
    }
    // Si l'index fourni correspond a une arme ou un bouclier on demande a l'utilisateur s'il est sur de vouloir supprimer
    else if (dynamic_cast<Weapon*>(m_itemsArray[indexItem]) ||  m_itemsArray[indexItem]->getType() == "SHIELD" ) {
        cout << "Vous allez supprimer un '" << m_itemsArray[indexItem]->getType() << "' de votre inventaire. \nEtes-vous sur ? [y/n] :" << endl;
        char answer;
        cin >> answer;
        // Verification de l'input
        if (answer == 'y' || answer == 'Y') {
            cout << m_itemsArray[indexItem]->getName() << " a ete supprimer" << endl;
            // Destruction de l'item
            delete m_itemsArray[indexItem];
            m_itemsArray[indexItem]=nullptr;
            // On retire le pointeur de l'item de l'inventaire
            m_itemsArray.erase(m_itemsArray.begin() + indexItem);
            return;
        }
        // Si l'utilisateur ne répond pas positivement on annule l'action
        cout << m_itemsArray[indexItem]->getName() << " n'a pas ete supprimer" << endl;
        return;
    }
    // UNIQUEMENT SI LE JOUEUR SOUHAITE PRENDRE UNE POTION
    delete m_itemsArray[indexItem];
    m_itemsArray.erase(m_itemsArray.begin() + indexItem);
}

// Renvoi un pointeur de Wand* pour que le hero puisse l'équiper
 Wand* Inventory::equipWand(const int indexItem){
    // On creer un Wand* temporaire qui permet de
    // verifier si l'index renvoie bien sur une 'WAND'
    Wand* wand = dynamic_cast<Wand*>(m_itemsArray[indexItem]);
    if (wand) {
        // Creation d'un pointeur de Wand*
        Wand* equippedWand = wand;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // On supprime la 'WAND' de l'inventaire mais on ne DETRUIT PAS l'item
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // Retire l'élément de l'inventaire
        return equippedWand;
    }
    // Si l'index fourni ne renvoi pas sur une 'WAND' on renvoi un pointeur vide
    return nullptr;
}

// Renvoi un pointeur de Sword* pour que le hero puisse l'équiper
Sword* Inventory::equipSword(const int indexItem){
    // On creer un Sword* temporaire qui permet de
    // verifier si l'index renvoie bien sur une 'SWORD'
    Sword* sword = dynamic_cast<Sword*>(m_itemsArray[indexItem]);
    if (sword) {
        // Creation d'un pointeur de Sword*
        Sword* equippedSword = sword;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // On supprime la 'SWORD' de l'inventaire mais on ne DETRUIT PAS l'item
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // Retire l'élément de l'inventaire
        return equippedSword;
    }
    // Si l'index fourni ne renvoi pas sur une 'SWORD' on renvoi un pointeur vide
    return nullptr;
}

// Renvoi un pointeur de Shield* pour que le hero puisse l'équiper
Shield* Inventory::equipShield(const int indexItem){
    // On creer un Shield* temporaire qui permet de
    // verifier si l'index renvoie bien sur un 'SHIELD'
    Shield* shield = dynamic_cast<Shield*>(m_itemsArray[indexItem]);
    if (shield) {
        // Creation d'un pointeur de Shield*
        Shield* equippedShield = shield;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // On supprime le 'SHIELD' de l'inventaire mais on ne DETRUIT PAS l'item
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // Retire l'élément de l'inventaire
        return equippedShield;
    }
    // Si l'index fourni ne renvoi pas sur un 'SHIELD' on renvoi un pointeur vide
    return nullptr;
}

// Renvoi le type d'item présent dans l'inventaire (SWORD,WAND,SHIELD,POTIONHEAL,POTIONSTRENGTH,POTIONDEFENSE)
string Inventory::getItemType(const int indexItem) const {
    // Si l'index fourni correspond a aucun item présent dans l'inventaire on renvoie une erreur
    if (indexItem < 0 || indexItem >= m_itemsArray.size()) {
        // cout << "The item that you want to remove is inexistant" << endl;
        return "The item you try to reach doesnt exist";
    }
    return m_itemsArray[indexItem]->getType();

}


string Inventory::getInventoryList() const {
    string list = "";
    for (unsigned int i = 0; i < m_itemsArray.size(); i++) {
        if (i == 3 || i == 6 || i == 9) {
            list += "\n";
        }
        list += "|[index " + to_string(i) + "]: " + m_itemsArray[i]->getName() + "|  ";
        // cout << "|[index " << i << "]: " << m_itemsArray[i]->getName() << " | ";
    }


    return list;
}


