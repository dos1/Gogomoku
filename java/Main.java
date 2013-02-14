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
		boolean ingame = true;
		while (ingame) {
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
						pawn='@';
						break;
					case 1:
						pawn='#';
						break;
					}

					System.out.print(pawn);
				}
				System.out.println();
			}
			
			
			PlayState state = game.getState();
			if (state == PlayState.WinWhite) {
				System.out.println("Game has ended with @'s win. Congratulations!");
				ingame=false;
			}
			else if (state == PlayState.WinBlack) {
				System.out.println("Game has ended with #'s win. Congratulations!");
				ingame=false;
			}
			else if (state == PlayState.Draw) {
				System.out.println("Game has ended with a draw. Try again next time!");
				ingame=false;
			} else {
			
			
				char pawn;
				if (game.getNextPlayer()==0) pawn='@'; else pawn='#';
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
						game.makeMove(y, x);
					} catch (UnallowedMove e) {
						System.out.println("Invalid move");
					} catch (MoveOutOfBounds e) {
						System.out.println("Move ouf of bounds [0-18]");
					} catch (Exception e) {
						System.out.println("Invalid command");
					}
	
				}
			}
		}
	}
}
