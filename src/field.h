#ifndef FIELD_H
#define FIELD_H

#include "pawn.h"
#include "stdio.h"
#include "gameboard.h"

class Field
{
public:
    int x;
    int y;
    Pawn *pwn;
    Gameboard *board;

    putPawn();
    clearField();
    bool isEmpty();
    int getColor();
    Field();
    Field(int x, int y, Gameboard *ptr);
    initialize(int x, int y, Gameboard *ptr);
    clearField();
};

#endif // FIELD_H
