//
// Created by hubert on 14.04.2023.
//

#ifndef CPP_WOLF_H
#define CPP_WOLF_H

#include "Animal.h"
#include "string"

class Wolf: public Animal {
private:
    static int amount;
public:
    Wolf(World &world, int xLocation, int yLocation);
    bool repel_attack(Body &attacker) override;
    static int getAmount_wolf();
    ~Wolf() override;
};


#endif //CPP_WOLF_H
