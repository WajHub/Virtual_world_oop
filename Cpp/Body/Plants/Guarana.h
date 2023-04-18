//
// Created by hubert on 18.04.2023.
//

#ifndef CPP_GUARANA_H
#define CPP_GUARANA_H


#include "../Plant.h"

class Guarana:public Plant {
private:
    static int amount;
public:
    Guarana(World &world, int xLocation, int yLocation);
    static int getAmount_guarana();
    int get_stronger() override;
    ~Guarana() override;
};


#endif //CPP_GUARANA_H
