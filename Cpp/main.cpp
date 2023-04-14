#include <conio.h>
#include "Wolf.h"

int main() {
    World world;
    Wolf wolf(world,5,1);
    world.add_body(wolf);
    while(true){
        world.draw_border();
        world.draw_world();
        world.make_turn();
        getch();
    }
    return 0;
}
