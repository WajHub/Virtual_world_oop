//
// Created by hubert on 13.04.2023.
//

#include "Body.h"
#include <iostream>
#include "World.h"


int Body::getXLocation() const {
    return x_location;
}

int Body::getYLocation() const {
    return y_location;
}

void Body::setXLocation(int xLocation) {
    x_location = xLocation;
}

void Body::setYLocation(int yLocation) {
    y_location = yLocation;
}

World &Body::getWorld() const {
    return world;
}

const std::string &Body::getName() const {
    return name;
}

char Body::getMark() const {
    return mark;
}

int Body::getPower() const {
    return power;
}

int Body::getInitiative() const {
    return initiative;
}

void Body::setName(const std::string &name) {
    Body::name = name;
}

void Body::setMark(char mark) {
    Body::mark = mark;
}

void Body::setPower(int power) {
    Body::power = power;
}

void Body::setInitiative(int initiative) {
    Body::initiative = initiative;
}


Body::~Body() {

}

Body::Body( World &world,int xLocation, int yLocation) : world(world), x_location(xLocation),
                                                                    y_location(yLocation) {}


void Body::draw() {
    gotoxy(SITE_X+x_location,SITE_Y+y_location);
    std::cout<<mark;
}

void Body::draw_news(std::string inf) {
    gotoxy(0,getWorld().getYNews());
    std::cout<<name<<"["<<mark<<"]"<<"("<<x_location<<", "<<y_location<<")";
    getWorld().setYNews(getWorld().getYNews()+1);
}

bool Body::isAbleToAction() const {
    return able_to_action;
}

void Body::setAbleToAction(bool ableToAction) {
    able_to_action = ableToAction;
}

int Body::getAge() const {
    return age;
}

void Body::setAge(int age) {
    Body::age = age;
}

void Body::incrementAge() {
 Body::age++;
}

void Body::random_location(Body &body,int &new_x, int &new_y) {
    World &world = getWorld();
    int x =body.getXLocation();
    int y = body.getYLocation();
    new_x=x;
    new_y=y;
    srand(time(NULL));
    int random;
    bool tmp = true;
    while (tmp) {
        random = (rand()+101+97*19)% 4 + 1;
        switch (random) {
            case 1:
                if (x < world.getXSize() && getWorld().getMap()[x][y-1]==' ') {
                    new_x++;
                    tmp=false;
                }
                break;
            case 2:
                if (x > 1 && getWorld().getMap()[x-2][y-1]==' ') {
                    new_x--;
                    tmp = false;
                }
                break;
            case 3:
                if (y < getWorld().getYSize() && getWorld().getMap()[x-1][y]==' ') {
                    new_y++;
                    tmp = false;
                }
                break;
            case 4:
                if (y > 1 && getWorld().getMap()[x-1][y-2]==' ') {
                    new_y--;
                    tmp = false;
                }
                break;
        }
    }
}

bool Body::isAlive() const {
    return alive;
}

void Body::setAlive(bool alive) {
    Body::alive = alive;
}

