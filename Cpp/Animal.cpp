//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Animal::random_location(int &new_x, int &new_y,int x, int y) {
    srand(time(NULL));
    int random;
    bool tmp = true;
    while (tmp) {
        random = (rand()+101+97*19)% 4 + 1;
        switch (random) {
            case 1:
                if (x < getWorld().getXSize()) {
                    new_x++;
                    tmp=false;
                }
                break;
            case 2:
                if (x > 1) {
                    new_x--;
                    tmp = false;
                }
                break;
            case 3:
                if (y < getWorld().getYSize()) {
                    new_y++;
                    tmp = false;
                }
                break;
            case 4:
                if (y > 1) {
                    new_y--;
                    tmp = false;
                }
                break;
        }
    }
}

void Animal::action() {
    //wypisanie informacji [organizm](pozycja)
    draw_news(getWorld().getYNews());
    int x =getXLocation();
    int y = getYLocation();
    int new_x=x;
    int new_y=y;
    random_location(new_x,new_y,x ,y);
    //Kolizja
    if(getWorld().getMap()[new_x-1][new_y-1]!=' '){

    }
    setXLocation(new_x);
    setYLocation(new_y);
    //Wypisanie czynnosci jaka wykonal organizm oraz zwiekszenie pozycji wyswietlania informacji
    getWorld().setYNews(getWorld().getYNews()+1);
    //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
    std::cout<<"-> Move to ("<<getXLocation()<<", "<<getYLocation()<<")";
    getWorld().getMap()[x-1][y-1]=' ';
    getWorld().getMap()[getXLocation()-1][getYLocation()-1]=getMark();
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






