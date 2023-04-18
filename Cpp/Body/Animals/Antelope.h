//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_ANTELOPE_H
#define CPP_ANTELOPE_H


#include "../Animal.h"

class Antelope: public Animal {
private:
    static int amount;
    bool repel_attack(Body &attacker) override;
protected:
    void action() override;
public:
    void collision(Body *other) override;
    Antelope(World &world, int xLocation, int yLocation);
    static int getAmount_antelopes();
    ~Antelope() override;
};

#endif //CPP_ANTELOPE_H
