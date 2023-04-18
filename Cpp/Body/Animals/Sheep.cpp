//
// Created by hubert on 17.04.2023.
//

#include "Sheep.h"

int Sheep::amount = 0;

Sheep::Sheep(World &world, int xLocation, int yLocation) :  Animal(world, xLocation,yLocation) {
    amount++;
    setName("Sheep");
    setMark('S');
    setInitiative(4);
    setPower(4);
}

bool Sheep::repel_attack(Body &attacker) {
    return false;
}

int Sheep::getAmount_sheep() {
    return amount;
}

Sheep::~Sheep() {
    Sheep::amount--;
}
