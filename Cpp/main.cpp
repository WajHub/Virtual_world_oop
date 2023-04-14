#include <conio.h>
#include "Wolf.h"


int main() {
    World world;
    world.add_body(*new Wolf(world,30,20));
    char c;
    while(true){
        world.draw_border();
        world.draw_world();
        world.make_turn();
        c=getch();
        if(c=='q') break;
    }
    c='a';
    return 0;
}
