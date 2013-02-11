#ifndef GAME_H
#define GAME_H

#include "playstate.h"
#include "history.h"
#include <ctime>

class Pawn;
class Gameboard;
class Field;
class Game {
    private:
				PlayState state_play;
        time_t time_begin;
        time_t time_end;
        Pawn *who_next;
                Gameboard *board;
        History the_story;
        int moves_done;
    public:
        Game();
        ~Game();
				void newGame();
        int numberOfMoves();
				void nextTurn();
				void undoTurn();
        PlayState winning(int who);
        PlayState drawing();
        void addHistory(Field next);
        void revertLastMove();
        Pawn *whoNext();
        PlayState getState();
        void stopTimer();
        time_t gameTime();
        Gameboard *getBoard();
};
#endif //GAME_H
