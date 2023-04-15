//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include "World.h"


class Animal: public Body {
protected:
    void print_out(std:: ostream& out)  const override;
public:
    Animal(World &world, int xLocation, int yLocation);
    void move(int new_x, int new_y,int x, int y);
    void random_location(int &new_x, int &new_y,int x, int y);
    void random_location_born(int &new_x,int &new_y,Body &other);
    void action() override;
    void collision(Body &other) override;
    virtual ~Animal() ;
};


#endif //CPP_ANIMAL_H
