#include "board.h"

enum PlayState {
	InProgress = 0,
	WinWhite,
	WinBlack,
	Draw
};

class Game {
	public:
		Board state;
		PlayState state_play;
		time_t time_begin;
}
