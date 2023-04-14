//
// Created by hubert on 14.04.2023.
//

#include "Wolf.h"



void Wolf::draw() {

}

Wolf::Wolf(World &world, int xLocation, int yLocation)
: Animal(world, xLocation,yLocation) {
    setName("Wolf");
    setMark('W');
    setInitiative(5);
    setPower(9);
}



