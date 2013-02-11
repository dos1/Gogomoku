#ifndef GAME_H
#define GAME_H

#include "playstate.h"
#include "history.h"
#include <ctime>

class Pawn;
class Gameboard;
class Field;
class Game {
	public:
				PlayState state_play;
        time_t time_begin;
        Pawn *who_next;
                Gameboard *board;
        History the_story;
        int moves_done;

        Game();
				void newGame();
        int numberOfMoves();
				void nextTurn();
				void undoTurn();
        PlayState winning(int who);
        PlayState drawing();
        void addHistory(Field next);
        void revertLastMove();
        Pawn *whoNext();
};
#endif //GAME_H
