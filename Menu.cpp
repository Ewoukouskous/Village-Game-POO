//
// Created by amiar on 04/11/2024.
//

#include "Menu.h"
// Will display with this format :
// ---Menu's name---
// 1. first action
// 2. second action
// ect.....
// -----------------
// Choose an option from [1 to 2]
void Menu::display() {
    cout << "---" << m_title << "---" << endl;
    for (size_t i = 0; i < m_options.size(); i++) {
        cout << i + 1 << ". " << m_options[i] << endl;
    }
    for (size_t i = 0; i < (m_title.size()+6); i++) {
        cout << "-";
    }
    cout << "\nChoose an option from [1 to "<< m_options.size() << "]"<< endl;
}