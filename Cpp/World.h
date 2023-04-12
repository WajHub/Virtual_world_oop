//
// Created by hubert on 11.04.2023.
//

#ifndef VIRTUAL_WORLD_WORLD_H
#define VIRTUAL_WORLD_WORLD_H


class World {
public:
    World();
    virtual ~World();
    void draw_world();
private:
    int x_size=20;
    int y_size=20;
    void print_menu_load_size();
    void load_size();
    void draw_bord();
    void make_turn();
};


#endif //VIRTUAL_WORLD_WORLD_H
