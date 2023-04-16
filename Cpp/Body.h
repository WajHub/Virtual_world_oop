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
protected:
    virtual void action () = 0;
    World &getWorld() const;
    virtual void draw_news(std::string inf);
    void setAge(int age);
    void setMark(char mark);
    void setPower(int power);
    void setInitiative(int initiative);
    void random_location(Body &body, int &new_x, int &new_y);
public:
    const std::string &getName() const;
    void setName(const std::string &name);
    int getPower() const;
    virtual void collision(Body *other) = 0;
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    int getXLocation() const;
    int getYLocation() const;
    void draw();
    void incrementAge();
    char getMark() const;
    int getAge() const;
    int getInitiative() const;
    virtual void back_move()=0;
    Body(World &world, int xLocation, int yLocation);
    virtual void move() =0;
    bool isAbleToAction() const;
    //organizm jest zdolny do ruchu jedna tura po jego utworzeniu
    void setAbleToAction(bool ableToAction);
    virtual ~Body();
};


#endif //CPP_BODY_H
