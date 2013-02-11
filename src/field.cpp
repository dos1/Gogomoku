#include "field.h"


Field::Field(){
    x=0;
    y=0;
    board=NULL;
    pwn=NULL;
}

Field::Field(int x, int y, Gameboard *ptr)
{
    this->x=x;
    this->y=y;
    this->board=ptr;
    this->pwn=NULL;
}

Field::initlialize(int x, int y, Gameboard *ptr){
    this->x=x;
    this->y=y;
    this->board=ptr;
    this->pwn=NULL;
}

Field::clearField()
{
    this->pwn=NULL;
}

int Field::getColor(){
    return pwn->getColor();
}

bool Field::isEmpty(){
    if(pwn==NULL){
        return TRUE;
    }
    return FALSE;
}

Field::putPawn(){
    if(pwn==NULL){
        //pawn=board->whoNext();
        //board->addHistory(*this);
        //board->checkState(x,y);
        //board->nextTurn();
    }
}
