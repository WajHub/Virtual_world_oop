//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Wolf.h"
#include <unistd.h>


void Animal::action() {
    World &world = getWorld();
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    srand(time(NULL));
    int random;
    bool tmp = true;
    while (tmp) {
        usleep(23057);
        random = (rand()+101+97*19)% 4 + 1;
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
    setXLocation(getLastPositionX());
    setYLocation(getLastPositionY());
}

void Animal::move() {
    World &world = getWorld();;
    action();
    if(world.getMap()[getXLocation()-1][getYLocation()-1]!=' '){
        //Kolizja
        Body *tmp = world.get_body(getXLocation(),getYLocation());
        collision(*tmp);
    }
    else{
        //wypisanie informacji [organizm](pozycja)
        draw_news(getWorld().getYNews());
        std::cout<<"-> Move to ("<<getXLocation()<<", "<<getYLocation()<<")";
        world.setYNews(getWorld().getYNews()+1);
        world.getMap()[last_position_x-1][last_position_y-1]=' ';
        world.getMap()[getXLocation()-1][getYLocation()-1]=getMark();
    }
}


void Animal::random_location_born(int &new_x, int &new_y, Body &other) {
//    World &world = getWorld();
//    int free_space1=world.free_spaces(*this);
//    int free_space2=world.free_spaces(other);
//    if(free_space1 == 0 && free_space2==0){
//        world.setYNews(world.getYNews()+1);
//        //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
//        std::cout<<"-> it's not able to gender (lack of space) ("<<getXLocation()<<", "<<getYLocation()<<")";
//    }
//    else if(free_space1 == 0){
//        new_x=other.getXLocation();
//        new_y=other.getYLocation();
//        while(true){
//            random_location(new_x,new_y,other.getXLocation(),other.getYLocation());
//            if(world.getMap()[new_x-1][new_y-1]!=' ') break;
//        }
//    }
//    else if(free_space2 == 0 ){
//        new_x=this->getXLocation();
//        new_y=this->getYLocation();
//        while(true){
//            random_location(new_x,new_y,this->getXLocation(),this->getYLocation());
//            if(world.getMap()[new_x-1][new_y-1]!=' ') break;
//        }
//    }
//        //Jesli obok obu zwierzat jest wolne miejsce, to losujemy zwierze, obok ktorego ma sie narodzic nowe
//    else{
//        srand(time(NULL));
//        int random=rand()%2;
//        if(random==0){
//            while(true){
//                new_x=other.getXLocation();
//                new_y=other.getYLocation();
//                random_location(new_x,new_y,other.getXLocation(),other.getYLocation());
//                if(world.getMap()[new_x-1][new_y-1]!=' ') break;
//            }
//        }
//        else{
//            while(true){
//                new_x=this->getXLocation();
//                new_y=this->getYLocation();
//                random_location(new_x,new_y,this->getXLocation(),this->getYLocation());
//                if(world.getMap()[new_x-1][new_y-1]!=' ') break;
//            }
//        }
//    }
}


void Animal::collision(Body &attacker) {
    //BORN
    if(attacker.getMark()==getMark()){
        back_move();
    }
    //ATTACK
    else{

    }
//    if(getAge()>0 && other.getAge()>0){
//        int new_x;
//        int new_y;
//        random_location_born(new_x,new_y,other);
//        //Born
//        switch(getMark()){
//            case 'W':
//                getWorld().add_body(*new Wolf(getWorld(),new_x,new_y));
//                getWorld().setYNews(getWorld().getYNews()+1);
//                std::cout<<"-> Born new Wolf ("<<new_x<<", "<<new_y<<")";
//                break;
//        }
//    }
//    //Nie dochodzi do rozmnazania z powodu za malego wieku ktoregos ze zwierzat
//    else{
//        getWorld().setYNews(getWorld().getYNews()+1);
//        //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
//        std::cout<<"-> it's not able to gender (too young) ("<<getXLocation()<<", "<<getYLocation()<<")";
//    }
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

void Animal::draw_news(int location) {
    gotoxy(0,location);
    std::cout<<getName()<<"["<<getMark()<<"]"<<"("<<getLastPositionX()<<", "<<getLastPositionY()<<")";
}













