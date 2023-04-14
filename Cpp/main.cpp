#include <conio.h>
#include "Wolf.h"

int main() {
    World world;
    world.draw_border();

    Wolf wolf(world,1,1);
    world.add_body(wolf);
    while(true){
        world.draw_world();
        getch();
    }
    return 0;
}
