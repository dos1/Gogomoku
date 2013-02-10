#include "field.h"


Field::Field(){
    x=0;
    y=0;
    board=NULL;
    pwn=NULL;
}

Field::Field(int x, int y, class Gameboard *ptr)
{
    this->x=x;
    this->y=y;
    this->board=ptr;
    this->pwn=NULL;
}

clearField::Field()
{
    this->pwn=NULL;
}
