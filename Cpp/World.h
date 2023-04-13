//
// Created by hubert on 11.04.2023.
//
#pragma once
#ifndef VIRTUAL_WORLD_WORLD_H
#define VIRTUAL_WORLD_WORLD_H
#include <list>
class Body;

class World {
private:
    std::list<Body*> area;
    int x_size=20;
    int y_size=20;
    void print_menu_load_size();
    void load_size();
public:
    World();
    void draw_border();
    virtual ~World();
    void draw_world();
    void make_turn();
    int getXSize() const;
    int getYSize() const;
};


#endif //VIRTUAL_WORLD_WORLD_H
