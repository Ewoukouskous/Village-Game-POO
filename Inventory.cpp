//
// Created by amiar on 24/10/2024.
//

#include "Inventory.h"

Inventory::Inventory() {
    // Default size = 10 spaces
    m_sizeMax = 10;
}

Inventory::~Inventory() {
    // Destroy every items of the inventory while it is not empty
    while (!m_itemsArray.empty()) {
        delete m_itemsArray.back(); // delete the last item of the vector
        m_itemsArray.pop_back();    // delete the pointer of the list
    }
}


// Add an item pointer int the inventory
void Inventory::addItem(Item* ptr_item) {
    // if the inventory's full : show an error
    if (m_itemsArray.size() >= m_sizeMax) {
        cout << "Your inventory is full, you can't add anything in it" << endl;
        return;
    }
    // if not, we add it in the end of the inventory
    m_itemsArray.push_back(ptr_item);
}

    // Remove an item pointer and delete it
void Inventory::removeItem(const int indexItem) {
        // If the index of the item is not an index of an item : show an error
    if (indexItem < 0 || indexItem >= m_itemsArray.size()) {
        cout << "The item that you want to remove is inexistant" << endl;
        return;
    }
        // If the item we want to delete is a weapon or a shield. It asks a confirmation
    else if (dynamic_cast<Weapon*>(m_itemsArray[indexItem]) ||  m_itemsArray[indexItem]->getType() == "SHIELD" ) {
        cout << "Vous allez supprimer un '" << m_itemsArray[indexItem]->getType() << "' de votre inventaire. \nEtes-vous sur ? [y/n] :" << endl;
        char answer;
        cin >> answer;
            // Check the input
        if (answer == 'y' || answer == 'Y') {
            cout << m_itemsArray[indexItem]->getName() << " a ete supprimer" << endl;
                // Destruction of the item
            delete m_itemsArray[indexItem];
            m_itemsArray[indexItem]=nullptr;
                // We remove the pointer item in the inventory
            m_itemsArray.erase(m_itemsArray.begin() + indexItem);
            return;
        }
        // If the user input isn't positive we don't do the action
        cout << m_itemsArray[indexItem]->getName() << " n'a pas ete supprimer" << endl;
        return;
    }
        // JUST IF THE PLAYER WANT TO TAKE A POTION
    delete m_itemsArray[indexItem];
    m_itemsArray.erase(m_itemsArray.begin() + indexItem);
}

// Return a wand pointer which can be equipped by the hero
 Wand* Inventory::equipWand(const int indexItem){
    // We create a temporary wand that check if the input is really a wand
    Wand* wand = dynamic_cast<Wand*>(m_itemsArray[indexItem]);
    if (wand) {
        // Creation of a wand pointer
        Wand* equippedWand = wand;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // We delete the wand in the inventory but we NOT delete the wand
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // Take of the inventory
        return equippedWand;
    }
    // If the index sended is not a wand pointer, return a null pointer
    return nullptr;
}

// Return a sword pointer
Sword* Inventory::equipSword(const int indexItem){
    // // We create a temporary sword that check if the input is really a sword
    Sword* sword = dynamic_cast<Sword*>(m_itemsArray[indexItem]);
    if (sword) {
        // Creation of a sword pointer
        Sword* equippedSword = sword;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // We delete the sword in the inventory but not the item
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // take of from the inventory
        return equippedSword;
    }
    // If the index returned is not a sword, it return a null pointer
    return nullptr;
}

// Return a shield pointer
Shield* Inventory::equipShield(const int indexItem){
    // // We create a temporary shield that check if the input is really a shield
    Shield* shield = dynamic_cast<Shield*>(m_itemsArray[indexItem]);
    if (shield) {
        // Creation of a shield pointer
        Shield* equippedShield = shield;
        cout << m_itemsArray[indexItem]->getName() << " a ete retire de l'inventaire"<<endl;
        // We delete the shield from the inventory but not the item
        m_itemsArray.erase(m_itemsArray.begin() + indexItem);  // Retire l'élément de l'inventaire
        return equippedShield;
    }
    // If the index returned is not a shield, it returns a null pointer
    return nullptr;
}

// return the type of the item asked
string Inventory::getItemType(const int indexItem) const {
    // Return an error if the index sended doesn't exist
    if (indexItem < 0 || indexItem >= m_itemsArray.size()) {
        return "The item you try to reach doesnt exist";
    }
    return m_itemsArray[indexItem]->getType();

}

    // Make a list of the item in the inventory
string Inventory::getInventoryList() const {
    string list = "";
    if (m_itemsArray.size() == 0) {
        cout << "Your inventory is empty :( " << endl;
    }
    for (unsigned int i = 0; i < m_itemsArray.size(); i++) {
        if (i == 3 || i == 6 || i == 9) {
            list += "\n";
        }
        list += "|[index " + to_string(i) + "]: " + m_itemsArray[i]->getName() + "|  ";
    }
    return list;
}
