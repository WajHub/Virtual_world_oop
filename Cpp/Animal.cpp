//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
void Animal::action() {
    srand(time(NULL));
    int random = rand() % 4 + 1;
    switch (random) {
        case 1:
            if(getXLocation()<getWorld().getXSize()-1){
                setXLocation(getXLocation()+1);
            }
            else{
                setXLocation(getXLocation()-1);
            }
            break;
        case 2:
            if(getXLocation()>0){
                setXLocation(getXLocation()-1);
            }
            else{
                setXLocation(getXLocation()+1);
            }
            break;
        case 3:
            if(getYLocation()<getWorld().getYSize()-1){
                setYLocation(getYLocation()+1);
            }
            else{
                setYLocation(getYLocation()-1);
            }
            break;
        case 4:
            if(getYLocation()>0){
                setYLocation(getYLocation()-1);
            }
            else{
                setYLocation(getYLocation()+1);
            }
            break;
    }
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




