//
// Created by hubert on 18.04.2023.
//

#include "Grass.h"
int Grass::amount = 0;
Grass::Grass(World &world, int xLocation, int yLocation) : Plant(world, xLocation, yLocation) {
    Grass::amount++;
    setName("Grass");
    setMark('G');
    setPower(0);
}

Grass::~Grass() {
    Grass::amount--;
}

int Grass::getAmount_grass() {
    return Grass::amount;
}

int Grass::get_stronger() {
    return 0;
}
