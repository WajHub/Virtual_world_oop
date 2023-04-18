//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_PLANT_H
#define CPP_PLANT_H

#include "Body.h"
#include "../World.h"

class Plant:public Body{
protected:
    virtual void action() override;
public:
    Plant(World &world, int xLocation, int yLocation);
    virtual void collision(Body *attacker) override;
    virtual int get_stronger()=0;
    void move() override;
    virtual ~Plant();
};


#endif //CPP_PLANT_H
