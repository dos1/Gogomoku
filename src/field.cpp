#include "field.h"

Field::Field(int x, int y, class Gameboard *ptr)
{
    this->x=x;
    this->y=y;
    this->board=ptr;
    this->pwn=NULL;
}
