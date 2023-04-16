//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <iostream>
#include "Wolf.h"
#include "Sheep.h"
#include <random>

void Animal::action() {
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
    while (tmp) {
        random = dis(gen);
        switch (random) {
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
    }
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
            random_location(other,new_x,new_y);
            if(world.getMap()[new_x-1][new_y-1]==' ') return true;
        }
    }
    else if(free_space2 == 0 ){
        new_x=this->getXLocation();
        new_y=this->getYLocation();
        while(true){
            random_location(*this,new_x,new_y);
            if(world.getMap()[new_x-1][new_y-1]==' ') return true;
        }
    }
    else{
        srand(time(NULL));
        int random=rand()%2;
        if(random==0){
            while(true){
                random_location(other,new_x,new_y);
                if(world.getMap()[new_x-1][new_y-1]==' ') return true;
            }
        }
        else{
            while(true){
                random_location(*this,new_x,new_y);
                if(world.getMap()[new_x-1][new_y-1]==' ') return true;
            }
        }
    }
}

void Animal::born(Body *attacker) {
    if(getAge()>0 && attacker->getAge()>0) {
        int new_x;
        int new_y;
        if(random_location_born(new_x,new_y,*attacker)){
            switch(getMark()){
                case'W':
                    getWorld().add_body(*new Wolf(getWorld(),new_x,new_y));
                    break;
                case'S':
                    getWorld().add_body(*new Sheep(getWorld(),new_x,new_y));
                    break;
            }
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
        attacker->back_move();
        born(attacker);
    }
    else{
        if(this->getPower()>attacker->getPower()){
            draw_news("-> dead ("+attacker->getName()+
                      std::to_string(getXLocation())+", "+
                      std::to_string(getYLocation())+")");
            world.delete_body2(attacker);
            world.getMap()[getXLocation()-1][getYLocation()-1]=getMark();
        }
        else{
            draw_news("-> dead ("+this->getName()+
                      std::to_string(getXLocation())+", "+
                      std::to_string(getYLocation())+")");
            world.delete_body(this);
            world.getMap()[attacker->getXLocation()-1][attacker->getYLocation()-1]=attacker->getMark();

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
    if(getWorld().getYNews()<30){
        gotoxy(0,getWorld().getYNews());
        std::cout<<getName()<<"["<<getMark()<<"]"<<"("<<getLastPositionX()<<", "<<getLastPositionY()<<")"<<inf;
        getWorld().setYNews(getWorld().getYNews()+1);
    }

}















