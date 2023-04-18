//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_GRASS_H
#define CPP_GRASS_H
#include "../Plant.h"

class Grass:public Plant {
private:
    static int amount;
public:
    Grass(World &world, int xLocation, int yLocation);
    static int getAmount_grass();
    int get_stronger() override;
    ~Grass() override;
};


#endif //CPP_GRASS_H
