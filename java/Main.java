import java.io.DataInputStream;
import java.io.IOException;

import playState.PlayState;
import field.Field.UnallowedMove;
import game.Game;
import gameboard.Gameboard;
import gameboard.Gameboard.MoveOutOfBounds;

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
			System.out.print("["+pawn+"] Type coordinates, \"undo\", \"new\" or \"exit\": ");
			
			DataInputStream in=new DataInputStream(System.in);
			
			@SuppressWarnings("deprecation")
			String key = in.readLine();
			
			if (key.equalsIgnoreCase("new")) {
				System.out.println("Starting new game...");
				game.newGame();
			} else if (key.equalsIgnoreCase("undo")) {
				System.out.println("Reverting last move...");
				game.revertLastMove();
			} else if (key.equalsIgnoreCase("exit")) {
				break;
			} else {
				int x, y;
				try {
					String[] myNumbers=key.split(" ");
					x=Integer.valueOf(myNumbers[0]).intValue();
					y=Integer.valueOf(myNumbers[1]).intValue();
				} catch (Exception e) {
					System.out.println("Invalid command");
					continue;
				}
				
                try {
					game.makeMove(y, x);
				} catch (UnallowedMove e) {
					System.out.println("Invalid move");
				} catch (MoveOutOfBounds e) {
					System.out.println("Move ouf of bounds [0-18]");
				}
				
			}
		}
		System.out.println(game.getState());
	}
}
