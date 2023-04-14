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
    //value starts from 1
    int x_location;
    int y_location;
    World &world;
protected:
    virtual void print_out(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Body& body);
public:
    virtual void action () = 0;
    virtual void collision(Body &other) = 0;
    void draw() ;
    Body(World &world, int xLocation, int yLocation);

    int getXLocation() const;
    int getYLocation() const;
    void setXLocation(int xLocation);
    void setYLocation(int yLocation);
    const std::string &getName() const;
    char getMark() const;
    int getPower() const;
    int getInitiative() const;
    World &getWorld() const;
    void setName(const std::string &name);
    void setMark(char mark);
    void setPower(int power);
    void setInitiative(int initiative);
    virtual ~Body();
};


#endif //CPP_BODY_H
