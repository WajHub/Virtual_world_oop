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

void Animal::move(int new_x, int new_y,int x, int y) {
    setXLocation(new_x);
    setYLocation(new_y);
    //Wypisanie czynnosci jaka wykonal organizm oraz zwiekszenie pozycji wyswietlania informacji
    getWorld().setYNews(getWorld().getYNews()+1);
    //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
    std::cout<<"-> Move to ("<<getXLocation()<<", "<<getYLocation()<<")";
    getWorld().getMap()[x-1][y-1]=' ';
    getWorld().getMap()[getXLocation()-1][getYLocation()-1]=getMark();
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
        Body *tmp = getWorld().get_body(new_x,new_y);
        if(tmp->getMark()==getMark()){
            collision(*tmp);
        }
        else{

        }
    }
    else{
        move(new_x,new_y,x,y);
    }

}

void Animal::random_location_born(int &new_x, int &new_y, Body &other) {
    int free_space1=getWorld().free_spaces(*this);
    int free_space2=getWorld().free_spaces(other);
    if(free_space1 == 0 && free_space2==0){
        getWorld().setYNews(getWorld().getYNews()+1);
        //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
        std::cout<<"-> it's not able to gender (lack of space) ("<<getXLocation()<<", "<<getYLocation()<<")";
    }
    else if(free_space1 == 0){
        new_x=other.getXLocation();
        new_y=other.getYLocation();
        while(true){
            random_location(new_x,new_y,other.getXLocation(),other.getYLocation());
            if(getWorld().getMap()[new_x-1][new_y-1]!=' ') break;
        }
    }
    else if(free_space2 == 0 ){
        new_x=this->getXLocation();
        new_y=this->getYLocation();
        while(true){
            random_location(new_x,new_y,this->getXLocation(),this->getYLocation());
            if(getWorld().getMap()[new_x-1][new_y-1]!=' ') break;
        }
    }
        //Jesli obok obu zwierzat jest wolne miejsce, to losujemy zwierze, obok ktorego ma sie narodzic nowe
    else{
        srand(time(NULL));
        int random=rand()%2;
        if(random==0){
            while(true){
                new_x=other.getXLocation();
                new_y=other.getYLocation();
                random_location(new_x,new_y,other.getXLocation(),other.getYLocation());
                if(getWorld().getMap()[new_x-1][new_y-1]!=' ') break;
            }
        }
        else{
            while(true){
                new_x=this->getXLocation();
                new_y=this->getYLocation();
                random_location(new_x,new_y,this->getXLocation(),this->getYLocation());
                if(getWorld().getMap()[new_x-1][new_y-1]!=' ') break;
            }
        }
    }
}


void Animal::collision(Body &other) {
    if(getAge()>0 && other.getAge()>0){
        int new_x;
        int new_y;
        random_location_born(new_x,new_y,other);
        //Born
        switch (this->getMark()) {
            case 'W':

        }
    }
    //Nie dochodzi do rozmnazania z powodu za malego wieku ktoregos ze zwierzat
    else{
        getWorld().setYNews(getWorld().getYNews()+1);
        //gotoxy jest ustawione poprawnie po wykonaniu funckji draw_news()
        std::cout<<"-> it's not able to gender (too young) ("<<getXLocation()<<", "<<getYLocation()<<")";
    }
}

Animal::~Animal() {

}

Animal::Animal(World &world, int xLocation, int yLocation)
: Body(world, xLocation, yLocation) {

}

void Animal::print_out(std::ostream &out) const {
    out << "Name: "<<getName()<<" Location("<<getXLocation()<<", "<<getYLocation()<<")"<<std::endl;
}











