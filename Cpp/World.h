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
    int x_size=10;
    int y_size=10;
    int turn=0;
    int y_news=SITE_Y_NEWS;
    int order=' ';
    bool human_is_alive=false;
    bool human_special_skill_is_active=false;
    void print_menu_load_size();
    void load_size();
    void human_special_skill();
    void print_objects(int number_obj[10]);
    void create_objects(int number_obj[10]);
public:
    World();
    void new_game();
    void draw_border();
    void draw_world();
    void make_turn();
    void add_body(Body &body);
    void delete_body(Body *body);
    void delete_body2(Body *body);
    int free_spaces(Body &body);
    bool isAnimal(int x, int y);
    Body* get_body(int x, int y);
    bool order_is_correct();

    bool isHumanIsAlive() const;
    void setHumanIsAlive(bool humanIsAlive);
    int getXSize() const;
    int getYSize() const;
    int getYNews();
    void setYNews(int yNews);
    char **getMap();
    void setOrder(char order);
    char getOrder() const;
    virtual ~World();
    static void test_map(World &world);
};


#endif //VIRTUAL_WORLD_WORLD_H
