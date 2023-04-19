//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <iostream>
#include <random>

void Animal::action() {
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    random_location(new_x, new_y);
    setLastPositionX(x);
    setLastPositionY(y);
    setXLocation(new_x);
    setYLocation(new_y);
}


void Animal::back_move() {
    int tmp_x=getXLocation();
    int tmp_y=getYLocation();
    setXLocation(getLastPositionX());
    setYLocation(getLastPositionY());
    setLastPositionX(tmp_x);
    setLastPositionY(tmp_y);
    getWorld().getMap()[getXLocation()-1][getYLocation()-1]=getMark();
}

void Animal::move() {
    World &world = getWorld();;
    action();
    if(changed_position()){
        if(world.getMap()[getXLocation()-1][getYLocation()-1]!=' '){
            //Kolizja
            this->back_move();
            world.getMap()[getXLocation()-1][getYLocation()-1]=' ';
            Body *tmp = world.get_body(getLastPositionX(),getLastPositionY());
            this->back_move();
            tmp->collision(this);
        }
        else{
            draw_news("-> Move to ("+std::to_string(getXLocation())+", "+std::to_string(getYLocation())+")");
            world.getMap()[last_position_x-1][last_position_y-1]=' ';
            world.getMap()[getXLocation()-1][getYLocation()-1]=getMark();
        }
    }
    else{
        draw_news("-> remains in place");
    }
}

bool Animal::random_location_born(int &new_x, int &new_y, Body &other) {
    World &world = getWorld();
    int free_space1=world.free_spaces(*this);
    int free_space2=world.free_spaces(other);
    if(free_space1 == 0 && free_space2==0){
        return false;
    }
    else if(free_space1 == 0){
        new_x=other.getXLocation();
        new_y=other.getYLocation();
        while(true){
            random_location_new_body(other, new_x, new_y);
            if(world.getMap()[new_x-1][new_y-1]==' ') return true;
        }
    }
    else if(free_space2 == 0 ){
        new_x=this->getXLocation();
        new_y=this->getYLocation();
        while(true){
            random_location_new_body(*this, new_x, new_y);
            if(world.getMap()[new_x-1][new_y-1]==' ') return true;
        }
    }
    else{
        srand(time(NULL));
        int random=rand()%2;
        if(random==0){
            while(true){
                random_location_new_body(other, new_x, new_y);
                if(world.getMap()[new_x-1][new_y-1]==' ') return true;
            }
        }
        else{
            while(true){
                random_location_new_body(*this, new_x, new_y);
                if(world.getMap()[new_x-1][new_y-1]==' ') return true;
            }
        }
    }
}

void Animal::born(Body *attacker) {
    if(getAge()>3 && attacker->getAge()>3) {
        int new_x;
        int new_y;
        if(random_location_born(new_x,new_y,*attacker)){
            new_body(new_x,new_y);
            draw_news("-> Born ("+
                                            std::to_string(new_x)+", "+
                                            std::to_string(new_y)+")");

        }
        else{
            draw_news("-> it's not able to gender (lack of space) ("+
                                            std::to_string(getXLocation())+", "+
                                            std::to_string(getYLocation())+")");

        }
    }
    else {
        draw_news("-> it's not able to gender (too young) ("+
                                                            std::to_string(getXLocation())+", "+
                                                            std::to_string(getYLocation())+")");
    }
}

void Animal::collision(Body *attacker) {
    World &world= getWorld();
    if(attacker->getMark()==getMark()){
        // dynamiczne rzutowanie na  typ Animal
        Animal *animalAttacker = dynamic_cast<Animal*>(attacker);
        //jesli rzutowanie sie powiedzie
        if(animalAttacker){
            animalAttacker ->back_move();
        }
        born(attacker);
    }
    else{
        if(this->getPower()>attacker->getPower()){
            draw_news("-> "+getName()+" kill "+attacker->getName()+" ("+
                      std::to_string(getXLocation())+", "+
                      std::to_string(getYLocation())+")");
            world.delete_body2(attacker);
            world.getMap()[getXLocation()-1][getYLocation()-1]=getMark();
        }
        else if(!this->repel_attack(*attacker)){
            draw_news("-> "+attacker->getName()+" kill "+this->getName()+" ("+
                      std::to_string(getXLocation())+", "+
                      std::to_string(getYLocation())+")");
            world.delete_body(this);
            world.getMap()[attacker->getXLocation()-1][attacker->getYLocation()-1]=attacker->getMark();
        }
        else{
            // dynamiczne rzutowanie na  typ Animal
            Animal *animalAttacker = dynamic_cast<Animal*>(attacker);
            //jesli rzutowanie sie powiedzie
            if(animalAttacker){
                animalAttacker ->back_move();
            }
            draw_news("-> "+attacker->getName()+" come back "+" ("+
                      std::to_string(getXLocation())+", "+
                      std::to_string(getYLocation())+")");
        }
    }
}

Animal::~Animal() {

}

Animal::Animal(World &world, int xLocation, int yLocation)
: Body(world, xLocation, yLocation) {
    setLastPositionX(xLocation);
    setLastPositionY(yLocation);
}

void Animal::setLastPositionX(int lastPositionX) {
    last_position_x = lastPositionX;
}

void Animal::setLastPositionY(int lastPositionY) {
    last_position_y = lastPositionY;
}

int Animal::getLastPositionX() const {
    return last_position_x;
}

int Animal::getLastPositionY() const {
    return last_position_y;
}

void Animal::draw_news(std::string inf) {
    if(getWorld().getYNews()<30) {
        gotoxy(4, getWorld().getYNews());
        std::cout << "(" << getLastPositionX() << ", "
        << getLastPositionY() << ")" << inf;
        getWorld().setYNews(getWorld().getYNews() + 1);
    }
}

bool Animal::changed_position() {
    if(getLastPositionX()!=getXLocation()||getLastPositionY()!=getYLocation()) return true;
    return false;
}

















