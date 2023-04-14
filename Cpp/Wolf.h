//
// Created by hubert on 14.04.2023.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H

#include "Animal.h"
#include "string"

class Wolf: public Animal {
public:
    Wolf(World &world, int xLocation, int yLocation);
    void draw();


};


#endif //CPP_WOLF_H
