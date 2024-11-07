//
// Created by ninol on 06/11/2024.
//

#ifndef HOSTEL_H
#define HOSTEL_H
#include "Building.h"


class Hostel: public Building {
private:
public:
    Hostel();

    void sellHeal(int choice, Hero *hero);

    string introduceBuilding() override;

};



#endif //HOSTEL_H
