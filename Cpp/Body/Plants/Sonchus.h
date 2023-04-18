//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_SONCHUS_H
#define CPP_SONCHUS_H


#include "../Plant.h"

class Sonchus: public Plant {
private:
    static int amount;
public:
    Sonchus(World &world, int xLocation, int yLocation);
    void action() override;
    static int getAmount_sonchus();
    int get_stronger() override;
    ~Sonchus() override;
};



#endif //CPP_SONCHUS_H
