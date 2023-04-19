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
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    int range=2;
    while (range>0) {
        random_location(new_x,new_y);
        setXLocation(new_x);
        setYLocation(new_y);
        if(new_x==x&& new_y==y) range=2;
        else range--;
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
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 199]
    std::uniform_int_distribution<> dis(0, 199);
    int random=dis(gen);
    if(random%2==0|| getWorld().free_spaces(*this)==0){
        Animal::collision(other);
    }
    else{
        int new_x;
        int new_y;
        random_location_empty(*this,new_x,new_y);
        other->draw_news("-> Move to ("+std::to_string(getXLocation())+", "+std::to_string(getYLocation())+")");
        getWorld().getMap()[getXLocation()-1][getYLocation()-1]=other->getMark();
        setLastPositionX(getXLocation());
        setLastPositionY(getYLocation());
        setXLocation(new_x);
        setYLocation(new_y);
        other->draw_news("-> Run away to ("+std::to_string(getXLocation())+", "+std::to_string(getYLocation())+")");
        getWorld().getMap()[getXLocation()-1][getYLocation()-1]=getMark();
    }
}
