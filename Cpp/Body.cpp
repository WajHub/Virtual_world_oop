//
// Created by hubert on 13.04.2023.
//

#include "Body.h"
#include <iostream>

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

std::ostream &operator<<(std::ostream &os, const Body &body) {
    body.print_out(os);
    return os;
}

void Body::draw() {
    gotoxy(SITE_X+x_location,SITE_Y+y_location);
    std::cout<<mark;
}

void Body::draw_news(int location) {
    gotoxy(0,location);
    std::cout<<name<<"["<<mark<<"]"<<"("<<x_location<<", "<<y_location<<")";
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

