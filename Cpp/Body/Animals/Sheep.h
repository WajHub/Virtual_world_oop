//
// Created by hubert on 17.04.2023.
//

#ifndef CPP_SHEEP_H
#define CPP_SHEEP_H
#include "../Animal.h"
#include "string"

class Sheep : public Animal{
private:
    static int amount;
    bool repel_attack(Body &attacker) override;
public:
    Sheep(World &world, int xLocation, int yLocation);
    static int getAmount_sheep();
    ~Sheep() override;
};


#endif //CPP_SHEEP_H
