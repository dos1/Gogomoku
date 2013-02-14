import java.io.DataInputStream;
import java.io.IOException;

import playState.PlayState;
import game.Game;
import gameboard.Gameboard;

public class Main {
	public static void main(String args[]) throws IOException {
		Game game = new Game();
		System.out.println(game.getState());
		while (game.getState()==PlayState.InProgress) {
			Gameboard board = game.getBoard();
			System.out.print(' ');
			for (int j=0; j<19; j++) {
				System.out.print(j%10);
			}
			System.out.println();
			for (int i=0; i<19; i++) {
				System.out.print(i%10);
				for (int j=0; j<19; j++) {
					int color = board.getColor(i, j);
					char pawn=' ';
					switch (color) {
					case -1:
						pawn='.';
						break;
					case 0:
						pawn='O';
						break;
					case 1:
						pawn='#';
						break;
					}
						
					System.out.print(pawn);
				}
				System.out.println();
			}
			char pawn;
			if (game.getNextPlayer()==0) pawn='O'; else pawn='#';
			System.out.print("["+pawn+"] Type coordinates, \"undo\" or \"new\": ");
			
			DataInputStream in=new DataInputStream(System.in);
			String key = in.readLine();
			
			if (key.equalsIgnoreCase("new")) {
				System.out.println("Starting new game...");
				game.newGame();
			} else if (key.equalsIgnoreCase("undo")) {
				System.out.println("Reverting last move...");
				game.revertLastMove();
			} else {
				String[] myNumbers=key.split(" ");
				int x=Integer.valueOf(myNumbers[0]).intValue();
				int y=Integer.valueOf(myNumbers[1]).intValue();
				
				if (board.getColor(y,x) == -1) game.makeMove(y, x);
			}
		}
		System.out.println(game.getState());
	}
}
