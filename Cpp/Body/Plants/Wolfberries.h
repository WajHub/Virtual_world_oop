//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_WOLFBERRIES_H
#define CPP_WOLFBERRIES_H


#include "../Plant.h"

class Wolfberries:public Plant {
private:
    static int amount;
public:
    Wolfberries(World &world, int xLocation, int yLocation);
    static int getAmount_Wolfberries();
    int get_stronger() override;
    ~Wolfberries() override;
};


#endif //CPP_WOLFBERRIES_H
