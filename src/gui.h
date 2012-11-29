class GUI : private interface {
	public:
		GUI();

		void make_game();
		void add_move(Move move);
		Move undo_move();
		void win_game();
}
