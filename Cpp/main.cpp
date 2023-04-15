#include <conio.h>
#include "Wolf.h"


int main() {
    World world;
    world.add_body(*new Wolf(world,30,20));
    world.add_body(*new Wolf(world,29,20));
    world.add_body(*new Wolf(world,29,19));
    world.add_body(*new Wolf(world,28,19));
    char c;
    while(true){
        world.draw_border();
        world.make_turn();
        world.draw_world();
        c=getch();
        if(c=='q') break;
    }
    c='a';
    return 0;
}
