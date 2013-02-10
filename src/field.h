#ifndef FIELD_H
#define FIELD_H

class Field
{
public:
    int x;
    int y;
    class Pawn *pwn;
    class Gameboard *board;

    putPawn();
    clearField();
    Field();
    Field(int x, int y, class Gameboard *ptr);
    clearField();
};

#endif // FIELD_H
