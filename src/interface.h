#include "move.h"

virtual class interface {
	public:
		Game game;

		interface();

		virtual void make_game();
		virtual void add_move(Move move);
		virtual Move undo_move();
		virtual void win_game();
}
