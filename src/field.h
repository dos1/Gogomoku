#ifndef FIELD_H
#define FIELD_H

//#include "pawn.h"
#include <cstdlib>
class Pawn;
class Gameboard;
class Field {
	public:
    int x;
    int y;
    Pawn *pwn;
    Gameboard *board;

		void putPawn();
		void clearField();
    bool isEmpty();
    int getColor();
    Field();
    Field(int x, int y, Gameboard *ptr);
		void initialize(int x, int y, Gameboard *ptr);
};

#endif // FIELD_H
