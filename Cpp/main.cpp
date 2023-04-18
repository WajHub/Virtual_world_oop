#include <conio.h>
#include "World.h"
#include "Body/Animals/Wolf.h"
#include "Body/Animals/Sheep.h"
#include "Body/Plants/Grass.h"
#include "Body/Plants/Guarana.h"
#include "Body/Plants/Pine_hogweed.h"
#include "Body/Plants/Sonchus.h"
#include "Body/Plants/Wolfberries.h"
int main() {
    World world;
//    world.add_body(*new Wolf(world,2,2));
//    world.add_body(*new Wolf(world,4,2));
//    world.add_body(*new Wolf(world,10,10));
//    world.add_body(*new Sheep(world,10,10));
//    world.add_body(*new Sheep(world,12,10));
//    world.add_body(*new Sheep(world,13,10));
//    world.add_body(*new Sheep(world,10,9));
//    world.add_body(*new Grass(world,10,1));
//    world.add_body(*new Grass(world,1,1));
//    world.add_body(*new Grass(world,2,1));
//    world.add_body(*new Wolf(world,8,7));
//    world.add_body(*new Guarana(world,7,8));
//    world.add_body(*new Guarana(world,20,20));
//    world.add_body(*new Sonchus(world,20,1));
//    world.add_body(*new Sonchus(world,1,1));
    world.add_body(*new Wolf(world,1,4));
    world.add_body(*new Pine_hogweed(world,1,1));

//    world.add_body(*new Wolf(world,2,2));
//    world.add_body(*new Wolf(world,4,2));
//        world.add_body(*new Sonchus(world,1,1));
    char c;

    while(true){
        world.make_turn();
        world.draw_world();
        c=getch();
        if(c=='w'){
            c='a';
        }
        if(c=='q') break;
        system("cls");
    }
    return 0;
}
