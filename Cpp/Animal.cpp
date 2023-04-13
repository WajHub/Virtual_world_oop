//
// Created by hubert on 13.04.2023.
//

#include "Animal.h"
#include <cstdlib>
#include <ctime>
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
