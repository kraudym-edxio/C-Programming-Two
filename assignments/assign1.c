/*
	assign1.c
	Assignment 1- Tic Tac Toe
	Coded by: Edxio Kraudy Mora (110006224)
	Date: February 5, 2020
*/

#include <stdio.h>
#include <stdlib.h>

//Function 1
void InitializeBoard (int m, int n, char board[][n]);

//Function 2
void PrintBoard (int m, int n, char board[][n]);

//Function 3
void CreateBoard (int m, int n, char board[][n]);

//Function 4
int IsValidBoard(int m, int n, char board[][n]);

//Function 5
void ListWinningCells (int m, int n, char board[][n]);

//Function 6
char WhoIsTheWinner (int m, int n, char board[][n]);

//Recursive Function for 6)
char winner_test (int m, int n, char board[][n], char winner);

//Function 7 (main)
int main(void) {

	int m = 3, n = 3;
	char board[3][3];
	
	InitializeBoard(m, n, board);

	char menu_select;
	
	do {
	
		printf("Press 'p' to print the Tic-Tac-Toe board.\n");
		printf("Press 'c' to create a Tic-Tac-Toe board with some X and O cells.\n");
		printf("Press 't' to test if a Tic-Tac-Toe board is a valid or invalid board.\n");
		printf("Press 'w' to predict winning cell(s) for player X or O.\n");
		printf("Press 'g' to determine the winner of the game.\n");
		printf("Press 'e' to exit.\n");

		printf("\nPlease make your selection: ");
		scanf(" %c", &menu_select);

		switch (menu_select) {
			
			case 'p':
				PrintBoard(m, n, board);
				break;

			case 'c':
				CreateBoard(m, n, board);				
				break;				

			case 't':
				IsValidBoard(m, n, board);
				break;

			case 'w':
				ListWinningCells(m, n, board);
				break;	

			case 'g':
				WhoIsTheWinner(m, n, board);
				break;	

			case 'e':
				printf("Thank you for playing!\n"); 
				menu_select = 0;
				break;

		}

	} while (menu_select != 0);

}

//Q1 Function (already provided)
void InitializeBoard (int m, int n, char board[][n]) {

	int c = 1;

	for (int i = 0; i < m; i++) {
		
		for (int j = 0; j < n; j++) {
			board[i][j] = c + '0';
			c++;
		}

	}

}

//Q2 Function 
void PrintBoard (int m, int n, char board[][n]) {

	printf("\n \n");
	
	//Priting the game board
	for (int i = 0; i < m; i++) {

		printf("\t|");
	
		for (int j = 0; j < n; j++) {
			
			printf("\t%c", board[i][j]);
			printf("\t|");

		}
	
		if (i < 2) {		
			printf("\n\n\t-------------------------------------------------\n\n");
		}

	}

	printf("\n \n \n");	

}

//Q3 Function
void CreateBoard (int m, int n, char board[][n]) {

	int selection;
	char symbol; 

	PrintBoard(m, n, board);
	
	while (selection != -1) {

		//Asing the user to make a cell selection	
		do {			

			printf("Enter the number of the cell where you want to insert X or O or enter -1 to exit: ");
			scanf("%d", &selection);

			if (selection == -1) {
				printf("Now exiting... taking you back to the menu.\n \n");
				break;
			}

		} while (selection < 1 || selection > 9);

		if (selection >= 1 && selection <= 9) {	

			//Prompting user to type either X or O
			while (1) {
		
				printf("Type X or O: ");
				scanf(" %c", &symbol);
						
				if (symbol == 'X' || symbol == 'O') {
					break;	
				}

			}	

			//Allocating the symbol based on the user selected cell
			for (int i = 0; i < m; i++) {

				for (int j = 0; j < n; j++) {
				
					if (board[i][j] == '0' + selection) {
						board[i][j] = symbol;
						break;
					}

				}

			}

			PrintBoard(m, n, board);

		}

	}

}

//Q4 Function 
int IsValidBoard (int m, int n, char board[][n]) {

	int x_Count = 0;
	int o_Count = 0;

	//Counting the total number of X's and O's on the board
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			
			if (board[i][j] == 'X') {
				x_Count++;
			}

			else if (board[i][j] == 'O') {
				o_Count++;
			}
	
		}

	}

	//Checking to see if the difference between X's and O's is invalid
	if (x_Count - o_Count > 1 || o_Count - x_Count > 1) {
		printf("Gameboard is currently invalid...\n \n \n");
		return 0;
	}

	else {
		printf("Gameboard is currently valid!\n \n \n");
		return 1;
	}

}

//Q5 Function
void ListWinningCells (int m, int n, char board[][n]) {

	int i = 0;
	int j = 0;
	
	int x_Count = 0;
	int o_Count = 0;

	//Counting number of X's and O's on board
	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			
			if (board[i][j] == 'X') {
				x_Count++;
			}

			else if (board[i][j] == 'O') {
				o_Count++;
			}
	
		}

	}

	//The following will ensure willing cells are not determined if the board is invalid
	
	if (x_Count - o_Count > 1 || o_Count - x_Count > 1) { //Board is not valid
		printf("Winning cells cannot be determined because the board is currently invalid!\n");
		printf("\n \n");
	}

	else { //Board is valid

		printf("The following cells are winning cells: \n \n");

		printf("With respect to columns:\n");
	
		//Checking columns
		while (j < 3) {

			if (board[0][j] == board[1][j]) {

				if (board[2][j] != 'X' && board [2][j] != 'O') {
					printf("#%c for %c\t", board[2][j], board[0][j]);
				}

			}	

			else if (board[0][j] == board[2][j]) {
			
				if (board[1][j] != 'X' && board[1][j] != 'O') {			
					printf("#%c for %c\t", board[1][j], board[0][j]);
				}

			}	

			else if (board[1][j] == board[2][j]) {
		
				if (board[0][j] != 'X' && board[0][j] != 'O') {
					printf("#%c for %c\t", board[0][j], board[1][j]);
				}
		
			}
	
			j++;

		}

		printf("\n \nWith repect to rows: \n");

		//Checking rows
		while (i < 3) {

			if (board[i][0] == board[i][1]) {

				if (board[i][2] != 'X' && board[i][2] != 'O') {
					printf("#%c for %c\t", board[i][2], board[i][0]);
				}

			}
	
			else if (board[i][0] == board[i][2]) {
			
				if (board[i][1] != 'X' && board[i][1] != 'O') {
					printf("#%c for %c\t", board[i][1], board[i][0]);
				}

			}	

			else if (board[i][1] == board[i][2]) {
			
				if (board[i][0] != 'X' && board[i][0] != 'O') {
					printf("#%c for %c\t", board[i][0], board[i][1]);
				}

			}

			i++;	

		}

		printf("\n \nWith respect to diagonals: \n");

		//Checking '\' diagonal
		if (board[0][0] == board[1][1]) {	
		
			if (board[2][2] != 'X' && board[2][2] != 'O') {
				printf("#%c for %c\t", board[2][2], board[0][0]);
			}
		
		}

		else if (board[0][0] == board[2][2]) {
	
			if (board[1][1] != 'X' && board[1][1] != 'O') {
				printf("#%c for %c\t", board[1][1], board[0][0]);
			}

		}

		else if (board[1][1] == board[2][2]) {
	
			if (board[0][0] != 'X' && board[0][0] != 'O') {
				printf("#%c for %c\t", board[0][0], board[1][1]);
			}
	
		}

		//Checking '/' diagonal
		if (board[0][2] == board[1][1]) {
	
			if (board[2][0] != 'X' && board[2][0] != 'O') {
				printf("#%c for %c\t", board[2][0], board[0][2]);
			}	

		}

		else if (board[0][2] == board[2][0]) {
	
			if (board[1][1] != 'X' && board[1][1] != 'O') {
				printf("#%c for %c\t", board[1][1], board[0][2]);
			}

		}

		else if (board[1][1] == board[2][0]) {
		
			if (board[0][2] != 'X' && board[0][2] != 'O') {
				printf("#%c for %c\t", board[0][2], board[1][1]);
			}	

		}
	
		printf("\n \n");

	}

}

//Q6 Functions
char WhoIsTheWinner (int m, int n, char board[][n]) {

	char winner = 'D';

	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
		winner = board[1][1];
	} 
	
	else {
		winner = winner_test(m, n, board, winner);
	}

	printf("The winner of the game is '%c'!\n \n \n", winner);

	return winner;
	
}
	
char winner_test (int m, int n, char board[][n], char winner) {

	static int j = 0;

	if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
		winner = board[0][j];
	}

	if (board[j][0] == board[j][1] && board[j][1] == board[j][2]) {
		winner = board[j][0];
	}

	j++;

	if (j < 3) {
		winner = winner_test(m, n, board, winner);
	}

	j = 0;

	return winner;

}
