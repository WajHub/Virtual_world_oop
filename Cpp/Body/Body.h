//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_BODY_H
#define CPP_BODY_H
#include "string"
#include "../Const.h"
#include "../mygotoxy.h"

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
    bool alive=true;
    World &world;
protected:
    virtual void draw_news(std::string inf);
    void random_location_new_body(Body &body, int &new_x, int &new_y);
    void random_location(int &new_x, int &new_y);
    virtual void action () = 0;

    World &getWorld() const;
    void setAge(int age);
    void setMark(char mark);
    void setInitiative(int initiative);
public:
    void new_body(int x, int y);
    virtual void collision(Body *other) = 0;
    virtual void move() =0;
    Body(World &world, int xLocation, int yLocation);

    void setAlive(bool alive);
    bool isAlive() const;
    const std::string &getName() const;
    void setPower(int power);
    void setName(const std::string &name);
    int getPower() const;
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    int getXLocation() const;
    int getYLocation() const;
    void draw();
    void incrementAge();
    char getMark() const;
    int getAge() const;
    int getInitiative() const;
    bool isAbleToAction() const;
    //organizm jest zdolny do ruchu jedna tura po jego utworzeniu
    void setAbleToAction(bool ableToAction);
    virtual ~Body();
};


#endif //CPP_BODY_H
