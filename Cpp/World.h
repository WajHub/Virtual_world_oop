//
// Created by hubert on 11.04.2023.
//
#pragma once
#ifndef VIRTUAL_WORLD_WORLD_H
#define VIRTUAL_WORLD_WORLD_H
#include <list>
#include "Body.h"
#include "Const.h"
#include <conio.h>
#include "mygotoxy.h"


class World {
private:
    std::list<Body*> bodies;
    int x_size=20;
    int y_size=20;
    int turn=1;
    void print_menu_load_size();
    void load_size();
public:
    World();
    void draw_border();
    virtual ~World();
    void draw_world();
    void make_turn();
    void add_body(Body &body);
    int getXSize() const;
    int getYSize() const;
};


#endif //VIRTUAL_WORLD_WORLD_H
