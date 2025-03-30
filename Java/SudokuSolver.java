import java.util.Scanner;
public class SudokuSolver {
	private static final int GRID_SIZE  = 9;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		//here zero is blank space in board
		int [][] board = new int[9][9];
		for (int i = 0; i < 9; i++) {
			System.out.println("Print line no: "+i);
            for (int j = 0; j < 9; j++) {
                board[i][j] = sc.nextInt();
            }
        }
		sc.close();
		/* 
		int[][] board = {
				{7,0,2,0,5,0,6,0,0},
				{0,0,0,0,0,3,0,0,0},
				{1,0,0,0,0,9,5,0,0},
				{8,0,0,0,0,0,0,9,0},
				{0,4,3,0,0,0,7,5,0},
				{0,9,0,0,0,0,0,0,8},
				{0,0,9,7,0,0,0,0,5},
				{0,0,0,2,0,0,0,0,0},
				{0,0,7,0,4,0,2,0,3}
		};
		*/
		System.out.println("\nBefore solving:\n");
		printBoard(board);
		if(solveBoard(board)) {
			System.out.println("\nSolved Successfully!!!!!!!!!");
			System.out.println("\nAfter solving:\n");
			printBoard(board);
		}
		else {
			System.out.println("Unsolvable!!!!!!!!!!!!!!");
		}
	}
	//return true is number already there
	private static boolean isNumberInRow(int[][] board, int number, int row) {
		for(int i=0; i<GRID_SIZE; i++) {
			if(board[row][i]==number) {
				return true;
			}
		}
		return false;
	}
	//return true is number already there
	private static boolean isNumberInColoumn(int[][] board, int number, int column) {
		for(int i=0; i<GRID_SIZE; i++) {
			if(board[i][column]==number) {
				return true;
			}
		}
		return false;
	}
	//return true is number already there
	private static boolean isNumberInBox(int[][] board, int number, int row, int column) {
		int localBoxRow = row - row%3;
		int localBoxColumn = column - column%3;
		
		for(int i=localBoxRow; i<localBoxRow+3; i++) {
			for(int j=localBoxColumn; j<localBoxColumn+3; j++) {
				if(board[i][j] == number) {
					return true;
				}
			}
		}
		return false;
	}
	//return false is number already there so not a valid placement
	//return true if number is not there, so can be placed, that's a valid placement
	private static boolean isValidPlacement(int[][] board, int number, int row, int column) {
		return !isNumberInRow(board, number, row) &&  
				!isNumberInColoumn(board, number, column) &&
				!isNumberInBox(board, number, row, column);
	}
	private static boolean solveBoard(int[][] board) {
		for(int row=0; row<GRID_SIZE; row++) {
			for(int column=0; column<GRID_SIZE; column++) {
				//if not blank then skip that sub-box
				if(board[row][column]==0) { //if blank then go
					for(int possibleNumber=1; possibleNumber<=GRID_SIZE; possibleNumber++) {
						if(isValidPlacement(board, possibleNumber, row, column)) {
							//if true then
							board[row][column] = possibleNumber; //the space got filled
							//now recursion 
							//because we can need backtracking 
							//because if the possibleNumber is not suitable for that space
							if(solveBoard(board)) {
								return true; //all placed successfully
							}
							else {//backtracking 
								board[row][column] = 0; //set back to blank
							}
						}
					} 
					//unable to find a valid number for that spot
					return false;
				}
			}
		}
		return true;
	}
	//method to print the board
		private static void printBoard(int[][] board) {
			for(int row=0; row<GRID_SIZE; row++) {
				if(row%3==0) {
					System.out.println("-------------------------");
				}
				for(int column=0; column<GRID_SIZE; column++) {
					if(column%3==0) {
						System.out.print("| ");
					}
					System.out.print(board[row][column]+" ");
				}
				System.out.print("|\n");
			}
			System.out.println("-------------------------");
		}
}