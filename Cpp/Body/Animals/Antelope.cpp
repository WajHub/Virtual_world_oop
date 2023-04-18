//
// Created by hubert on 18.04.2023.
//

#include <random>
#include "Antelope.h"
int Antelope::amount=0;

bool Antelope::repel_attack(Body &attacker) {
    return false;
}

void Antelope::action() {
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
    int range=2;
    while (range>0) {
        random = dis(gen);
        switch (random%5+1) {
            case 1:
                if (new_x < getWorld().getXSize()) {
                    new_x++;
                    range--;
                }
                break;
            case 2:
                if (new_x > 1) {
                    new_x--;
                    range--;
                }
                break;
            case 3:
                if (new_y < getWorld().getYSize()) {
                    new_y++;
                    range--;
                }
                break;
            case 4:
                if (new_y > 1) {
                    new_y--;
                    range--;
                }
                break;
        }
        if(new_x==x&& new_y==y){
            range=2;
            new_x=x;
            new_y=y;
        }
    }
    setLastPositionX(x);
    setLastPositionY(y);
    setXLocation(new_x);
    setYLocation(new_y);
}

Antelope::Antelope(World &world, int xLocation, int yLocation) : Animal(world, xLocation, yLocation) {
    Antelope::amount++;
    setName("Antelope");
    setMark('A');
    setInitiative(4);
    setPower(4);
}

int Antelope::getAmount_antelopes() {
    return Antelope::amount;
}

Antelope::~Antelope() {
    Antelope::amount--;
}

void Antelope::collision(Body *other) {

}
