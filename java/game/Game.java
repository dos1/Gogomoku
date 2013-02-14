package game;

import java.util.Date;

import playState.PlayState;
import pawn.BlackPawn;
import pawn.Pawn;
import pawn.WhitePawn;
import gameboard.Gameboard;
import gameboard.Gameboard.MoveOutOfBounds;
import history.History;
import field.Field;
import field.Field.UnallowedMove;

public class Game {
	private PlayState state_play;
	private Date time_begin;
	private Date time_end;
	private Pawn who_next;
	private Gameboard board;
	private History the_story;
	private int moves_done;
	
	public Game() {
		who_next = null;
		board = new Gameboard(this);
		the_story = new History();
		this.newGame();
	}
	public void finalize() {}
	
	public void newGame() {
		time_begin = new Date();
		time_end = null;
		who_next = new BlackPawn();
		state_play = PlayState.InProgress;
		moves_done = 0;
		the_story.cleanHistory();
		board.cleanBoard();
	}
	public int numberOfMoves() {
		return moves_done;
	}
	private void nextTurn() {
		if (who_next.getColor() == 0)
			who_next = new BlackPawn();
		else
			who_next = new WhitePawn();
		moves_done++;
	}
	private void undoTurn() {
		if (who_next.getColor() == 0)
			who_next = new BlackPawn();
		else
			who_next = new WhitePawn();
		moves_done--;
	}
	
	public int getNextPlayer() {
		return who_next.getColor();
	}
	
	public PlayState winning(int who) {
		if (who == 0)
			state_play = PlayState.WinWhite;
		else
			state_play = PlayState.WinBlack;
		stopTimer();
		return state_play;
	}
	public PlayState drawing() {
		state_play = PlayState.Draw;
		stopTimer();
		return state_play;
	}
	public void addHistory(Field next) {
		the_story.addToHistory(next);
	}
	public void revertLastMove() {
		Field pom;
		if (the_story.notEmpty()) {
			pom = the_story.takeFromHistory();
			board.revertMove(pom.getX(), pom.getY());
			undoTurn();
		}
	}
	public Pawn whoNext() {
		return who_next;
	}
	public PlayState getState() {
		return state_play;
	}
	public void stopTimer() {
		time_end = new Date();
	}
	public Date gameTime() {
		if (time_end != null)
			return new Date(time_end.getTime() - time_begin.getTime());
		else
			return new Date(new Date().getTime() - time_begin.getTime());
	}
	public Gameboard getBoard() {
		return board;
	}
		
	public void makeMove(int x, int y) throws UnallowedMove, MoveOutOfBounds {
		board.makeMove(x, y);
		this.nextTurn();
	}
}
