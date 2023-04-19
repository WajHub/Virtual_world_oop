//
// Created by hubert on 13.04.2023.
//
#include <iostream>
#include "Plant.h"
#include <random>
void Plant::collision(Body *attacker) {
    World &world= getWorld();
    if(this->getPower()>attacker->getPower()){
        draw_news("-> eat ("+attacker->getName()+
            std::to_string(getXLocation())+", "+
            std::to_string(getYLocation())+") and moments later dies");
        world.delete_body2(attacker);
        world.delete_body(this);
        world.getMap()[getXLocation()-1][getYLocation()-1]=' ';
    }
    else{
        draw_news("-> eat "+attacker->getName()+" ("+
            std::to_string(getXLocation())+", "+
            std::to_string(getYLocation())+")");
        if(get_stronger()>0){
            attacker->setPower(attacker->getPower()+get_stronger());
            draw_news(attacker->getName()+" getting stronger +"+std::to_string(get_stronger()));
        }

        world.delete_body(this);
        world.getMap()[attacker->getXLocation()-1][attacker->getYLocation()-1]=attacker->getMark();
    }
}


void Plant::move() {
    action();
}

void Plant::action() {
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 200]
    std::uniform_int_distribution<> dis(0, 200);
    int random = dis(gen);
    if(random%100<11){
        int free_space = getWorld().free_spaces(*this);
        if(free_space>0){
            int new_x;
            int new_y;
            random_location_new_body(*this, new_x, new_y);
            new_body(new_x,new_y);
            draw_news("-> new plant "+getName()+" ("+
                      std::to_string(new_x)+", "+
                      std::to_string(new_y)+")");
        }
    }
}

Plant::Plant(World &world, int xLocation, int yLocation) : Body(world, xLocation, yLocation) {
    setInitiative(0);
}

Plant::~Plant() {

}
