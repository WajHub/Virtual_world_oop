//
// Created by hubert on 11.04.2023.
//

#include "World.h"
#include <iostream>
#include "mygotoxy.h"
#include "Body/Animals/Wolf.h"
#include "Body/Animals/Sheep.h"
#include "Body/Animals/Fox.h"
#include "Body/Animals/Turtle.h"
#include "Body/Plants/Grass.h"
#include "Body/Plants/Guarana.h"
#include "Body/Plants/Pine_hogweed.h"
#include "Body/Plants/Sonchus.h"
#include "Body/Plants/Wolfberries.h"

World::World() {
    load_size();
    system("cls");
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
            // sprawdzamy czy zmienic polozenie strzalki ->
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
                if(loading_x_size && x_size<50) x_size++;
                else if(y_size<23) y_size++;
                break;
        }
    }
    map= new char*[x_size];
    for (int i = 0; i < x_size; i++) {
        map[i] = new char [y_size];
        for (int j = 0; j < y_size; j++) {
            map[i][j] = ' ';
        }
    }
}

void World::draw_border() {
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
    std::cout<<" LEGEND: "
    <<"W - Wolf ("<<Wolf::getAmount_wolf()<<") "
    <<"S - Sheep ("<<Sheep::getAmount_sheep()<<") "
    <<"F - Fox ("<<Fox::getAmount_fox()<<") "
    <<"T - Turtle ("<<Turtle::getAmount_turtle()<<") "
    <<std::endl<<"G - Grass ("<<Grass::getAmount_grass()<<") "
    <<"U - Guarana ("<<Guarana::getAmount_guarana()<<") "
    <<"P - Pine_hogweed ("<<Pine_hogweed::getAmount_Pine_hogweed()<<") "
    <<"O - Sonchus ("<<Sonchus::getAmount_sonchus()<<") "
    <<"B - Wolfberries ("<<Wolfberries::getAmount_Wolfberries()<<") ";
    gotoxy(0,6);
    std::cout<<char(25)<<"[NEWS]"<<char(25);
}

void World::draw_world() {
    draw_border();
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->draw();
    }
    World::test_map(*this);
}

void World::make_turn() {
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        if((*it)->isAbleToAction()){
            gotoxy(0,y_news);
            std::cout<<"["<<(*it)->getMark()<<"]";
            (*it)->incrementAge();
            (*it)->move();
            if(!(*it)->isAlive()){
                delete *it;
                it = bodies.erase(it);
                it++;
            }
        }
        else (*it)->setAbleToAction(true);
    }
    turn++;
    y_news=SITE_Y_NEWS;
}

World::~World() {
    for (auto it = bodies.begin(); it != bodies.end(); ++it) {
        delete *it;
    }

    for (int i = 0; i < x_size; i++) {
        delete[] map[i];
    }
    delete[] map;
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
            map[body.getXLocation()-1][body.getYLocation()-1]=body.getMark();
            return ;
        }
        //Gdy maja taka sama inicjatywe
        else if((*it)->getInitiative()==body.getInitiative()){

        }
    }
    bodies.push_back(&body);
    map[body.getXLocation()-1][body.getYLocation()-1]=body.getMark();
}

void World::delete_body(Body *body) {
    map[body->getXLocation()-1][body->getYLocation()-1]=' ';
    bodies.remove(body);
    delete body;
}
//Usuniecie organizmu, ktory teraz wykonuje ruch (Problem z usunieciem iteratora podczas iterowania po petli w funkcji make_turn)
void World::delete_body2(Body *body) {
    map[body->getXLocation()-1][body->getYLocation()-1]=' ';
    body->setAlive(false);
}

int World::getYNews()  {
    return y_news;
}

void World::setYNews(int yNews) {
    y_news = yNews;
}

char **World::getMap() {
    return map;
}

Body* World::get_body(int x, int y) {
    std::list<Body*>::iterator it;
    for (it = bodies.begin(); it != bodies.end(); ++it) {
        if ((*it)->getXLocation()==x &&(*it)->getYLocation()==y) {
            return (*it);
        }
    }
    return nullptr;
}

int World::free_spaces(Body &body) {
    int result = 0;
    int x=body.getXLocation();
    int y=body.getYLocation();
    if(x==1){
        if(map[1][y-1]==' ') result++;
    }
    else if(x==x_size){
        if(map[x-2][y-1]==' ') result++;
    }
    else{
        if(map[x][y-1]==' ') result++;
        if(map[x-2][y-1]==' ') result++;
    }
    if(y==1){
        if(map[x-1][1]==' ') result++;
    }
    else if(y==y_size){
        if(map[x-1][y-2]==' ') result++;
    }
    else{
        if(map[x-1][y]==' ') result++;
        if(map[x-1][y-2]==' ') result++;
    }
    return result;
}

void World::test_map(World &world) {
    for(int i=0;i<world.getXSize();i++){
        for(int j=0;j<world.getYSize();j++){
            gotoxy(SITE_X+world.getXSize()+5+i,SITE_Y+1+j);
            std::cout<<world.getMap()[i][j];
        }
    }
}

bool World::isAnimal(int x, int y) {
    switch(map[x-1][y-1]){
        case 'W':
            return true;
        case 'S':
            return true;
        case 'H':
            return true;
        case 'F':
            return true;
        case 'A':
            return true;
        case 'T':
            return true;
        default:
            return false;
    }

}




