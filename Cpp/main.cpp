#include <conio.h>
#include "Wolf.h"

int main() {
    World world;
    system("cls");
    world.add_body(*new Wolf(world,2,2));
    world.add_body(*new Wolf(world,2,1));
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
    c='a';
    return 0;
}
