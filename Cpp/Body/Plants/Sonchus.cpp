//
// Created by hubert on 18.04.2023.
//

#include <random>
#include "Sonchus.h"

int Sonchus::amount =0;

Sonchus::Sonchus(World &world, int xLocation, int yLocation) : Plant(world, xLocation, yLocation) {
    Sonchus::amount++;
    setName("Sonchus");
    setMark('O');
    setPower(0);
}

int Sonchus::getAmount_sonchus() {
    return Sonchus::amount;
}

Sonchus::~Sonchus() {
    Sonchus::amount--;
}

int Sonchus::get_stronger() {
    return 0;
}

void Sonchus::action() {
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 200]
    std::uniform_int_distribution<> dis(0, 200);
    for(int i=3;i>0;i--){
        int random = dis(gen);
        if(random%100<11) {
            int free_space = getWorld().free_spaces(*this);
            if (free_space > 0) {
                int new_x;
                int new_y;
                random_location(*this, new_x, new_y);
                new_body(new_x, new_y);
                draw_news("-> new plant " + getName() + " (" +
                          std::to_string(new_x) + ", " +
                          std::to_string(new_y) + ")");
            }
        }
    }
}
