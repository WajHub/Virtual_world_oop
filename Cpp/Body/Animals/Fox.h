//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_FOX_H
#define CPP_FOX_H


#include "../Animal.h"

class Fox: public Animal {
private:
    static int amount;
    bool repel_attack(Body &attacker) override;
protected:
    void action() override;
public:
    Fox(World &world, int xLocation, int yLocation);
    static int getAmount_fox();
    ~Fox() override;
};


#endif //CPP_FOX_H
