#include <conio.h>
#include "mygotoxy.h"
#include "World.h"
#include "Body/Animals/Wolf.h"
#include "Body/Animals/Sheep.h"
#include "Body/Animals/Fox.h"
#include "Body/Animals/Turtle.h"
#include "Body/Animals/Antelope.h"
#include "Body/Plants/Grass.h"
#include "Body/Plants/Guarana.h"
#include "Body/Plants/Pine_hogweed.h"
#include "Body/Plants/Sonchus.h"
#include "Body/Plants/Wolfberries.h"
#include "Body/Animals/Human.h"

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
