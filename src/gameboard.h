#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "field.h"
#include "game.h"

class Gameboard
{
public:
    Field tab[19][19];
    class Game *game;
    Gameboard();
};

#endif // GAMEBOARD_H
