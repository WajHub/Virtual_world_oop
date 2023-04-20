#include <conio.h>
#include "mygotoxy.h"
#include "World.h"

int main() {
    ShowConsoleCursor(false);
    World world;
    world.new_game();
    while(world.getOrder()!='q'){
        world.make_turn();
        world.draw_world();
        do{
            world.setOrder(getch());
        }while(!world.order_is_correct());
        system("cls");
    }

    return 0;
}
