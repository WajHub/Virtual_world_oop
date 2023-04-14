//
// Created by hubert on 11.04.2023.
//

#include "World.h"
#include <iostream>
#include "mygotoxy.h"


World::World() {
    load_size();
}

void World::print_menu_load_size() {
    gotoxy(1,1);
    std::cout<<"===NEW WORLD====================";
    for(int i=2;i<10;i++){
        gotoxy(1,i);
        std::cout<<char(179);
        gotoxy(32,i);
        std::cout<<char(179);
    }
    gotoxy(1,10);
    std::cout<<"================================";
    gotoxy(3,2);
    std::cout<<"Press enter to confirm.";
    gotoxy(6,4);
    std::cout<<"Size X: "<<x_size<<"  ";
    gotoxy(6,5);
    std::cout<<"Size Y: "<<y_size<<"  ";
}

void World::load_size() {
    char ch=' ';
    bool loading_x_size=true;
    system("cls");
    while(ch!=13){
        print_menu_load_size();
        if(loading_x_size){
            gotoxy(2,5);
            std::cout<<"  ";
            gotoxy(2,4);
            std::cout<<"->";
        }
        else{
            gotoxy(2,4);
            std::cout<<"  ";
            gotoxy(2,5);
            std::cout<<"->";
        }
        ch=getch();
        switch (ch){
            case 72:
                if(loading_x_size) loading_x_size=false;
                else loading_x_size=true;
                break;
            case 80:
                if(loading_x_size) loading_x_size=false;
                else loading_x_size=true;
                break;
            case 75:
                if(loading_x_size && x_size > 4) x_size--;
                else if(y_size>4) y_size--;
                break;
            case 77:
                if(loading_x_size) x_size++;
                else y_size++;
                break;
        }
    }
    map= new char*[x_size];
    for (int i = 0; i < x_size; i++) {
        map[i] = new char [y_size];
    }
}

void World::draw_border() {
    system("cls");
    gotoxy(0,1);
    std::cout<<"Welcome in your virtual world! (Hubert Wajda 193511)"<<char(179)<<" Turn game:"<<turn;
    for(int i=1;i<=x_size;i++){
        gotoxy(i+SITE_X,SITE_Y);
        std::cout<<char(196);
        gotoxy(i+SITE_X,SITE_Y+1+y_size);
        std::cout<<char(196);
    }
    for(int i=1;i<=y_size;i++){
        gotoxy(SITE_X,SITE_Y+i);
        std::cout<<char(179);
        gotoxy(SITE_X+x_size+1,SITE_Y+i);
        std::cout<<char(179);
    }
    //NAROZNIKI
    gotoxy(SITE_X,SITE_Y);
    std::cout<<char(218);
    gotoxy(SITE_X+x_size+1,SITE_Y);
    std::cout<<char(191);
    gotoxy(SITE_X,SITE_Y+y_size+1);
    std::cout<<char(192);
    gotoxy(SITE_X+x_size+1,SITE_Y+y_size+1);
    std::cout<<char(217);
    gotoxy(0,3);
    std::cout<<char(25)<<"[NEWS]"<<char(25)<<"  "<<char(179)<<" LEGEND: "<<"W - Wolf" ;
}

void World::draw_world() {
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->draw();
    }
}

void World::make_turn() {
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        if((*it)->isAbleToAction())(*it)->action();
        else (*it)->setAbleToAction(true);
    }
    turn++;
    y_news=4;
}

World::~World() {
//    for (auto it = bodies.begin(); it != bodies.end(); ++it) {
//        delete *it;
//    }
//    for (int i = 0; i < x_size; i++) {
//        delete[] map[i];
//    }
//    delete[] map;
}

int World::getXSize() const {
    return x_size;
}

int World::getYSize() const {
    return y_size;
}

void World::add_body(Body &body) {
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it){
        if((*it)->getInitiative()<body.getInitiative()){
            bodies.insert(it,1,&body);
            return ;
        }
        //Gdy maja taka sama inicjatywe
        else if((*it)->getInitiative()==body.getInitiative()){

        }
    }
    bodies.push_back(&body);
    map[body.getXLocation()-1][body.getYLocation()-1]=body.getMark();
}

int World::getYNews() const {
    return y_news;
}

void World::setYNews(int yNews) {
    y_news = yNews;
}

char **World::getMap() {
    return map;
}
