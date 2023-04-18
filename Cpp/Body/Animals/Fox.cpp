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
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 200]
    std::uniform_int_distribution<> dis(0, 200);
    int random;
    bool tmp = true;
    int attempt=0;
    while (tmp) {
        random = dis(gen);
        switch (random%5+1) {
            case 1:
                if (x < getWorld().getXSize()) {
                    new_x++;
                    tmp=false;
                }
                break;
            case 2:
                if (x > 1) {
                    new_x--;
                    tmp = false;
                }
                break;
            case 3:
                if (y < getWorld().getYSize()) {
                    new_y++;
                    tmp = false;
                }
                break;
            case 4:
                if (y > 1) {
                    new_y--;
                    tmp = false;
                }
                break;
        }
        // jesli jest silniejszy przeciwnik
        if(world.isAnimal(new_x,new_y) && !tmp){
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
