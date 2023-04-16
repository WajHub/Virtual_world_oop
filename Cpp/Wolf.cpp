//
// Created by hubert on 14.04.2023.
//

#include "Wolf.h"


int Wolf::amount = 0;

Wolf::Wolf(World &world, int xLocation, int yLocation)
: Animal(world, xLocation,yLocation) {
    amount++;
    setName("Wolf");
    setMark('W');
    setInitiative(5);
    setPower(9);
}

Wolf::~Wolf() {
    Wolf::amount--;
}

bool Wolf::repel_attack(Body &attacker) {
    return false;
}

int Wolf::getAmount_wolf() {
    return amount;
}



