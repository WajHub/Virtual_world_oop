//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
void Animal::action() {
    //wypisanie informacji [organizm](pozycja)
    draw_news(getWorld().getYNews());
    srand(time(NULL));
    int random;
    int x =getXLocation();
    int y = getYLocation();
    bool tmp = true;
    while (tmp) {
        random = (rand()+101+97*19)% 4 + 1;
        switch (random) {
            case 1:
                if (x < getWorld().getXSize()) {
                    setXLocation(x + 1);
                    tmp=false;
                }
                break;
            case 2:
                if (x > 1) {
                    setXLocation(x - 1);
                    tmp = false;
                }
                break;
            case 3:
                if (y < getWorld().getYSize()) {
                    setYLocation(y + 1);
                    tmp = false;
                }
                break;
            case 4:
                if (y > 1) {
                    setYLocation(y - 1);
                    tmp = false;
                }
                break;
        }
    }
    //Wypisanie czynnosci jaka wykoanl organizm oraz zwiekszenie pozycji wyswietlania informacji
    getWorld().setYNews(getWorld().getYNews()+1);
    //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
    std::cout<<"-> Move to ("<<getXLocation()<<", "<<getYLocation()<<")";
}

void Animal::collision(Body &other) {

}

Animal::~Animal() {

}

Animal::Animal(World &world, int xLocation, int yLocation)
: Body(world, xLocation, yLocation) {

}

void Animal::print_out(std::ostream &out) const {
    out << "Name: "<<getName()<<" Location("<<getXLocation()<<", "<<getYLocation()<<")"<<std::endl;
}




