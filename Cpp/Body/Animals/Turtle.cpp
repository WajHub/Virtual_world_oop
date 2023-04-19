//
// Created by hubert on 18.04.2023.
//

#include <random>
#include "Turtle.h"

int Turtle::amount = 0;

bool Turtle::repel_attack(Body &attacker) {
    if(attacker.getPower()<5)return true;
    return false;
}

Turtle::Turtle(World &world, int xLocation, int yLocation) : Animal(world, xLocation, yLocation) {
    Turtle::amount++;
    setName("Turtle");
    setMark('T');
    setInitiative(1);
    setPower(2);
}

int Turtle::getAmount_turtle() {
    return Turtle::amount;
}

Turtle::~Turtle() {
    Turtle::amount--;
}

void Turtle::action() {
    World &world = getWorld();
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 200]
    std::uniform_int_distribution<> dis(0, 200);
    int random=dis(gen);
    if(random%100<25){
        random_location( new_x, new_y);
    }
    setLastPositionX(x);
    setLastPositionY(y);
    setXLocation(new_x);
    setYLocation(new_y);
}
