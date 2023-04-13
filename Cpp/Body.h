//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_BODY_H
#define CPP_BODY_H
#include "World.h"

class Body {
private:
    char mark;
    int power;
    int initiative;
    int x_location;
    int y_location;
    World &world;
public:
    virtual void action () = 0;
    virtual void collision() = 0;
    virtual void draw() = 0;
    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    World &getWorld() const;

};


#endif //CPP_BODY_H
