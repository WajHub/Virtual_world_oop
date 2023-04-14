//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include "World.h"
#include "Body.h"


class Animal: public Body {
protected:
    void print_out(std:: ostream& out)  const override;
public:
    Animal(World &world, int xLocation, int yLocation);
    void action() override;
    void collision(Body &other) override;
    virtual void draw() = 0;
    virtual ~Animal() ;
};


#endif //CPP_ANIMAL_H
