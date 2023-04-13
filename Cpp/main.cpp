#include "World.h"
#include "conio.h"

int main() {
    World world;
    world.draw_border();
    getch();
    world.draw_world();

    return 0;
}
