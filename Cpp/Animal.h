//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include "World.h"


class Animal: public Body {
private:
    int last_position_x;
    int last_position_y;
protected:
    void random_location_born(int &new_x,int &new_y,Body &other);
    void back_move();
    void setLastPositionX(int lastPositionX);
    void setLastPositionY(int lastPositionY);
    int getLastPositionX() const;
    int getLastPositionY() const;
    void draw_news(int location) override;
public:
    Animal(World &world, int xLocation, int yLocation);
    virtual bool repel_attack(Body &attacker)=0;
    void move();
    virtual void action() override;
    virtual void collision(Body &other) override;
    virtual ~Animal() ;
};


#endif //CPP_ANIMAL_H
