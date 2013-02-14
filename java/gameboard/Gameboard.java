package gameboard;

import pawn.Pawn;
import playState.PlayState;
import game.Game;
import field.Field;

public class Gameboard {
	private Field tab[][];
	private Game game;
	
	public Gameboard(Game ptr) {
		game = ptr;
		int i, j;
		tab = new Field[19][];
		for (i = 0; i < 19; i++) {
			tab[i] = new Field[19];
			for (j = 0; j < 19; j++) {
				tab[i][j] = new Field();
				tab[i][j].initialize(i, j, this);
			}
		}
	}
    public void finalize() {
    	cleanBoard();
    }
    
    public void cleanBoard(){
    	int i, j;
    	for (i = 0; i < 19; i++)
    		for (j = 0; j < 19; j++)
    			tab[i][j].ClearField();
    }
    public void makeMove(int x, int y) {
    	
        tab[x][y].putPawn();
    }
    public void revertMove(int x, int y) {
    	tab[x][y].ClearField();
    }
    public void addHistory(Field next) {
    	game.addHistory(next);
    }
    public int getColor(int x, int y) {
    	return tab[x][y].getColor();
    }
    public PlayState checkState(int x,int y) {
    	int color = getColor(x,y);
    	int i=0, j=0;
    	int counter;
    	
    	counter = 1;
    	i = x + 1;
    	while ((i < (x+5)) && (i < 19))
    		if (!(tab[i][y].isEmpty()) && (color == tab[i][y].getColor())) {
    			counter++;
    			i++;
    		} else
    			break;
    	i = x - 1;
    	while ((i > (x-5)) && (i >= 0))
    		if (!(tab[i][y].isEmpty()) && (color == tab[i][y].getColor())) {
    			counter++;
    			i--;
    		} else
    			break;
    	if (counter >= 5)
    		return game.winning(color);
    	
    	counter = 1;
    	j = y + 1;
    	while((j < (y+5)) && (j < 19))
    		if (!(tab[x][j].isEmpty()) && (color == tab[x][j].getColor())) {
    			counter++;
    			j++;
    		} else
    			break;
    	j = y - 1;
    	while ((j > (y-5)) && (j >= 0))
    		if (!(tab[x][j].isEmpty()) && (color == tab[x][j].getColor())) {
    			counter++;
    			j--;
    		} else
    			break;
    	if (counter >= 5)
    		return game.winning(color);
    	
    	counter = 1;
    	i = x + 1;
    	j = y + 1;
    	while ((i < (x+5)) && (j < (y+5)) && (i < 19) && (j < 19))
    		if (!(tab[i][j].isEmpty()) && (color == tab[i][j].getColor())) {
    			counter++;
    			i++;
    			j++;
    		} else
    			break;
    	i = x - 1;
    	j = y - 1;
    	while ((i > (x - 5)) && (j > (y-5)) && (i >= 0) && (j >= 0))
    		if (!(tab[i][j].isEmpty()) && (color == tab[i][j].getColor())) {
    			counter++;
    			i--;
    			j--;
    		} else
    			break;
    	if (counter >= 5)
    		return game.winning(color);
    	
    	counter = 1;
    	i = x + 1;
    	j = y - 1;
    	while ((i < (x+5)) && (j > (y-5)) && (i < 19) && (j >= 0))
    		if (!(tab[i][j].isEmpty()) && (color == tab[i][j].getColor())) {
    			counter++;
    			i++;
    			j--;
    		} else
    			break;
    	i = x - 1;
    	j = y + 1;
    	while ((i > (x-5)) && (j < (y+5)) && (i >= 0) && (j < 19))
    		if (!(tab[i][j].isEmpty()) && (color == tab[i][j].getColor())) {
    			counter++;
    			i--;
    			j++;
    		} else
    			break;
    	if (counter >= 5)
    		return game.winning(color);
    	
    	if (game.numberOfMoves() == (19*19))
    		return game.drawing();
    	
    	return PlayState.InProgress;
    }
    public void nextTurn() {
    	game.nextTurn();
    }
    public Pawn whoNext() {
    	return game.whoNext();
    }
}
