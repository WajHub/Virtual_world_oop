//
// Created by hubert on 11.04.2023.
//

#include "World.h"
#include "mygotoxy.h"
#include "conio.h"
#include <iostream>

#define SITE_X 20
#define SITE_Y 5

World::World() {
    load_size();
}

void World::print_menu_load_size() {
    gotoxy(1,1);
    std::cout<<"===NEW WORLD====================";
    for(int i=2;i<10;i++){
        gotoxy(1,i);
        std::cout<<"|";
        gotoxy(32,i);
        std::cout<<"|";
    }
    gotoxy(1,10);
    std::cout<<"================================";
    gotoxy(3,2);
    std::cout<<"Press enter to confirm.";
    gotoxy(6,4);
    std::cout<<"Size X: "<<x_size;
    gotoxy(6,5);
    std::cout<<"Size Y: "<<y_size;
}

void World::load_size() {
    char ch=' ';
    system("cls");
    bool loading_x_size=true;
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
}

void World::draw_bord() {
    system("cls");
    gotoxy(1,1);
    std::cout<<"Welcome in your virtual world!";
    for(int i=0;i<=x_size;i++){
        gotoxy(i+SITE_X,SITE_Y);
        std::cout<<"#";
        gotoxy(i+SITE_X,SITE_Y+1+y_size);
        std::cout<<"#";
    }
    for(int i=1;i<=y_size;i++){
        gotoxy(SITE_X,SITE_Y+i);
        std::cout<<"#";
        gotoxy(SITE_X+x_size,SITE_Y+i);
        std::cout<<"#";
    }
    getch();
}

void World::draw_world() {
    draw_bord();
}

void World::make_turn() {

}

World::~World() {

}
