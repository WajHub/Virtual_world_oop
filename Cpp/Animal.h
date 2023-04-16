//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include "World.h"


class Animal: public Body {
public:
    Animal(World &world, int xLocation, int yLocation);
    virtual bool repel_attack(Body &attacker)=0;
    void move(int new_x, int new_y,int x, int y);
    void random_location(int &new_x, int &new_y,int x, int y);
    void random_location_born(int &new_x,int &new_y,Body &other);
    virtual void action() override;
    virtual void collision(Body &other) override;
    virtual ~Animal() ;
};


#endif //CPP_ANIMAL_H
