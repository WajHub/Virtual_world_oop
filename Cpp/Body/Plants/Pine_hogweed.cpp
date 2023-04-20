//
// Created by hubert on 18.04.2023.
//

#include <random>
#include "Pine_hogweed.h"
int Pine_hogweed::amount=0;
Pine_hogweed::Pine_hogweed(World &world, int xLocation, int yLocation) : Plant(world, xLocation, yLocation) {
    Pine_hogweed::amount++;
    setName("Pine hogweed");
    setMark('P');
    setPower(999);
}

int Pine_hogweed::getAmount_Pine_hogweed() {
    return Pine_hogweed::amount;
}

int Pine_hogweed::get_stronger() {
    return 0;
}

Pine_hogweed::~Pine_hogweed() {
    Pine_hogweed::amount--;
}

void Pine_hogweed::collision(Body *attacker) {
    World &world= getWorld();
    draw_news("-> eat ("+attacker->getName()+
              std::to_string(getXLocation())+", "+
              std::to_string(getYLocation())+") and moments later dies");
    world.delete_body2(attacker);
    world.getMap()[getXLocation()-1][getYLocation()-1]=' ';
    world.delete_body(this);
}

void Pine_hogweed::action() {
    // Utwórz generator pseudolosowy z ziarnem pobranym z urządzenia losującego
    std::random_device rd;
    std::mt19937 gen(rd());
    // Ustaw przedział generowania liczb pseudolosowych na [0, 200]
    std::uniform_int_distribution<> dis(0, 200);
    int random = dis(gen);
    if (random % 100 < 1) {
        int free_space = getWorld().free_spaces(*this);
        if (free_space > 0) {
            int new_x;
            int new_y;
            random_location_empty(*this, new_x, new_y);
            new_body(new_x, new_y);
            draw_news("-> new plant " + getName() + " (" +
                      std::to_string(new_x) + ", " +
                      std::to_string(new_y) + ")");
        }
    }
    kill_around();
}

void Pine_hogweed::kill_around() {
    World &world = getWorld();
    int x=getXLocation();
    int y=getYLocation();
    if(x==1){
        if(world.isAnimal(x+1,y)) {
            draw_news("-> kill "+world.get_body(x+1,y)->getName()+
                "("+std::to_string(world.get_body(x+1,y)->getXLocation())+", "+
                    std::to_string(world.get_body(x+1,y)->getYLocation())+")");
            world.delete_body(world.get_body(x+1,y));
        }
    }
    else if(x==world.getXSize()){
        if(world.isAnimal(x-1,y)) {
            draw_news("-> kill "+world.get_body(x-1,y)->getName()+
                      "("+std::to_string(world.get_body(x-1,y)->getXLocation())+", "+
                      std::to_string(world.get_body(x-1,y)->getYLocation())+")");
            world.delete_body(world.get_body(x-1,y));
        }
    }
    else{
        if(world.isAnimal(x+1,y)) {
            draw_news("-> kill "+world.get_body(x+1,y)->getName()+
                      "("+std::to_string(world.get_body(x+1,y)->getXLocation())+", "+
                      std::to_string(world.get_body(x+1,y)->getYLocation())+")");
            world.delete_body(world.get_body(x+1,y));
        }
        if(world.isAnimal(x-1,y)) {
            draw_news("-> kill "+world.get_body(x-1,y)->getName()+
                      "("+std::to_string(world.get_body(x-1,y)->getXLocation())+", "+
                      std::to_string(world.get_body(x-1,y)->getYLocation())+")");
            world.delete_body(world.get_body(x-1,y));
        }
    }
    if(y==1){
        if(world.isAnimal(x,y+1)) {
            draw_news("-> kill "+world.get_body(x,y+1)->getName()+
                      "("+std::to_string(world.get_body(x,y+1)->getXLocation())+", "+
                      std::to_string(world.get_body(x,y+1)->getYLocation())+")");
            world.delete_body(world.get_body(x,y+1));
        }
    }
    else if(y==world.getYSize()){
        if(world.isAnimal(x,y-1)) {
            draw_news("-> kill "+world.get_body(x,y-1)->getName()+
                      "("+std::to_string(world.get_body(x,y-1)->getXLocation())+", "+
                      std::to_string(world.get_body(x,y-1)->getYLocation())+")");
            world.delete_body(world.get_body(x,y-1));
        }
    }
    else{
        if(world.isAnimal(x,y+1)) {
            draw_news("-> kill "+world.get_body(x,y+1)->getName()+
                      "("+std::to_string(world.get_body(x,y+1)->getXLocation())+", "+
                      std::to_string(world.get_body(x,y+1)->getYLocation())+")");
            world.delete_body(world.get_body(x,y+1));
        }
        if(world.isAnimal(x,y-1)) {
            draw_news("-> kill "+world.get_body(x,y-1)->getName()+
                      "("+std::to_string(world.get_body(x,y-1)->getXLocation())+", "+
                      std::to_string(world.get_body(x,y-1)->getYLocation())+")");
            world.delete_body(world.get_body(x,y-1));
        }
    }
}
