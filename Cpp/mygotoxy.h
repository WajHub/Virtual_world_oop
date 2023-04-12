//
// Created by hubert on 12.04.2023.
//

#ifndef VIRTUAL_WORLD_MYGOTOXY_H
#define VIRTUAL_WORLD_MYGOTOXY_H

#include "windows.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


#endif //VIRTUAL_WORLD_MYGOTOXY_H
