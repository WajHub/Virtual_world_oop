//
// Created by hubert on 18.04.2023.
//

#include "Wolfberries.h"
int Wolfberries::amount = 0;
Wolfberries::Wolfberries(World &world, int xLocation, int yLocation) : Plant(world, xLocation, yLocation) {
    Wolfberries::amount++;
    setName("Wolfberries");
    setMark('B');
    setPower(999);
}

int Wolfberries::getAmount_Wolfberries() {
    return Wolfberries::amount;
}

int Wolfberries::get_stronger() {
    return 0;
}

Wolfberries::~Wolfberries() {
    Wolfberries::amount--;
}
