//
// Created by hubert on 13.04.2023.
//
#pragma once
#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H
#include "../World.h"
#include "string"

class Animal: public Body {
private:
    int last_position_x;
    int last_position_y;
    bool random_location_born(int &new_x,int &new_y,Body &other);
    void born(Body *attacker);
    void back_move();
protected:
    bool changed_position();
    void setLastPositionX(int lastPositionX);
    void setLastPositionY(int lastPositionY);
    int getLastPositionX() const;
    int getLastPositionY() const;

    virtual void action() override;
    virtual void collision(Body *other) override;
    virtual bool repel_attack(Body &attacker)=0;
public:
    void draw_news(std::string inf) override;
    Animal(World &world, int xLocation, int yLocation);
    void move();
    virtual ~Animal() ;
};


#endif //CPP_ANIMAL_H
