#include <conio.h>
#include "Wolf.h"
#include "Sheep.h"

int main() {
    World world;
    world.add_body(*new Wolf(world,2,2));
    world.add_body(*new Wolf(world,2,1));
    world.add_body(*new Sheep(world,2,3));
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
