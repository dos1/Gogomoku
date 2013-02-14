#ifndef FIELD_H
#define FIELD_H

//#include "pawn.h"
#include <cstdlib>
#include <exception>
class Pawn;
class Gameboard;
class Field {
	private:
		int x;
		int y;
		Pawn *pwn;
		Gameboard *board;
	public:
        class UnallowedMove{
        public:
            UnallowedMove(){

            }
        };

		void putPawn();
		void clearField();
		int getX();
		int getY();
		bool isEmpty();
		int getColor();
		Field();
		Field(int x, int y, Gameboard *ptr);
		void initialize(int x, int y, Gameboard *ptr);
};

#endif // FIELD_H
