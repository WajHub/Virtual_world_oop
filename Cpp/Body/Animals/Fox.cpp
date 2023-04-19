//
// Created by hubert on 18.04.2023.
//

#include "Fox.h"
#include <random>

int Fox::amount=0;

bool Fox::repel_attack(Body &attacker) {
    return false;
}

Fox::Fox(World &world, int xLocation, int yLocation) : Animal(world, xLocation, yLocation) {
    Fox::amount++;
    setName("Fox");
    setMark('F');
    setInitiative(7);
    setPower(3);
}

Fox::~Fox() {
    Fox::amount--;
}

int Fox::getAmount_fox() {
    return Fox::amount;
}

void Fox::action() {
    World &world = getWorld();
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    bool tmp = true;
    int attempt=0;
    while (tmp) {
        random_location( new_x, new_y);
        tmp=false;
        // jesli jest silniejszy przeciwnik
        if(world.isAnimal(new_x,new_y)){
            if(world.get_body(new_x,new_y)->getPower()>getPower()){
                new_x=x;
                new_y=y;
                tmp = true;
                attempt++;
                if(attempt>12){
                    tmp = false;
                }
            }
        }
    }
    setLastPositionX(x);
    setLastPositionY(y);
    setXLocation(new_x);
    setYLocation(new_y);
}
