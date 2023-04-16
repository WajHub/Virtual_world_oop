//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_BODY_H
#define CPP_BODY_H
#include "string"
#include "Const.h"
#include "mygotoxy.h"

class World;

class Body {
private:
    std::string name;
    char mark;
    int power;
    int initiative;
    int age=0;
    //value starts from 1
    int x_location;
    int y_location;
    bool able_to_action=false;
    World &world;
public:
    Body(World &world, int xLocation, int yLocation);
    virtual void action () = 0;
    virtual void collision(Body &other) = 0;
    void draw();
    void draw_news(int location);
    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    const std::string &getName() const;
    char getMark() const;
    int getPower() const;
    void setAge(int age);
    int getAge() const;
    int getInitiative() const;
    World &getWorld() const;
    void setName(const std::string &name);
    void setMark(char mark);
    void setPower(int power);
    void setInitiative(int initiative);
    bool isAbleToAction() const;
    //organizm jest zdolny do ruchu jedna tura po jego utworzeniu
    void setAbleToAction(bool ableToAction);
    virtual ~Body();
};


#endif //CPP_BODY_H
