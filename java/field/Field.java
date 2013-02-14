package field;

import pawn.Pawn;
import gameboard.Gameboard;

public class Field {
	private int x;
	private int y;
	private Pawn pwn;
	private Gameboard board;
	
	public Field() {
		x = 0;
		y = 0;
		board = null;
		pwn = null;
	}
	public Field(int x, int y, Gameboard ptr) {
		this.x = x;
		this.y = y;
		this.board = ptr;
		this.pwn = null;
	}
	
	@SuppressWarnings("serial")
	public class UnallowedMove extends Exception {

		public UnallowedMove() {}
	}

	public void putPawn() throws UnallowedMove {
		if (pwn == null) {
			this.pwn = board.whoNext();
			board.addHistory(this);
			board.checkState(x, y);
			board.nextTurn();
		} else {
			throw new Field.UnallowedMove();
		}
	}
	public void ClearField() {
		this.pwn = null;
	}
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}
	public boolean isEmpty() {
		if (pwn == null)
			return true;
		return false;
	}
	public int getColor() {
		if (pwn!=null) return pwn.getColor();
		else return -1;
	}
	public void initialize(int x, int y, Gameboard ptr) {
		this.x = x;
		this.y = y;
		this.board = ptr;
		this.pwn = null;
	}
}
