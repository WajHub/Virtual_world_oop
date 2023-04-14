//
// Created by hubert on 14.04.2023.
//

#include "mygotoxy.h"
#include "windows.h"


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
