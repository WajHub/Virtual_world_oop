//
// Created by hubert on 11.04.2023.
//
#pragma once
#ifndef VIRTUAL_WORLD_WORLD_H
#define VIRTUAL_WORLD_WORLD_H
#include <list>
#include "Body/Body.h"
#include "Const.h"
#include <conio.h>
#include "mygotoxy.h"



class World {
private:
    std::list<Body*> bodies;
    char **map;
    int x_size=3;
    int y_size=3;
    int turn=1;
    int y_news=SITE_Y_NEWS ;
    void print_menu_load_size();
    void load_size();
public:
    World();
    void draw_border();
    void draw_world();
    void make_turn();
    void add_body(Body &body);
    void delete_body(Body *body);
    void delete_body2(Body *body);
    int free_spaces(Body &body);
    bool isAnimal(int x, int y);
    Body* get_body(int x, int y);
    int getXSize() const;
    int getYSize() const;
    int getYNews();
    void setYNews(int yNews);
    char **getMap();
    virtual ~World();
    static void test_map(World &world);
};


#endif //VIRTUAL_WORLD_WORLD_H
