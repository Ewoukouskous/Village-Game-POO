//
// Created by amiar on 23/10/2024.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string m_name;
    int m_price;
public:
    virtual ~Item() = default;

    Item(const string &name, const int &price);
    virtual string getType() = 0 ;
    virtual int use() = 0 ;
    // GETTERS
    const string & getName() const {
        return m_name;
    }

    const int getPrice() const {
        return m_price;
    }
};



#endif //ITEM_H
