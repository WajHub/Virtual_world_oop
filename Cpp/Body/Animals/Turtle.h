//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_TURTLE_H
#define CPP_TURTLE_H


#include "../Animal.h"

class Turtle: public Animal {
private:
    static int amount;
    bool repel_attack(Body &attacker) override;
protected:
    void action() override;
public:
    Turtle(World &world, int xLocation, int yLocation);
    static int getAmount_turtle();
    ~Turtle() override;
};


#endif //CPP_TURTLE_H
