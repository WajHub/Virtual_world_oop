//
// Created by hubert on 18.04.2023.
//

#include "Guarana.h"
int Guarana::amount = 0;
Guarana::Guarana(World &world, int xLocation, int yLocation) : Plant(world, xLocation, yLocation) {
    Guarana::amount++;
    setName("Guarana");
    setMark('U');
    setPower(0);
}

int Guarana::getAmount_guarana() {
    return Guarana::amount;
}

int Guarana::get_stronger() {
    return 3;
}

Guarana::~Guarana() {
    Guarana::amount--;
}
