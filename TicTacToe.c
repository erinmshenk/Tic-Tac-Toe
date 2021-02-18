/*
	Erin Shenk
	CS 451
	Tic-Tac-Toe Game
	02/16/2021
*/

#include <stdio.h>

//initiates game board
void board(char table[3][3])
{	
	//prints blank game board
	printf("  %c | %c | %c \n", table[0][0], table[0][1], table[0][2]);
	printf("------------- \n");
	printf("  %c | %c | %c \n", table[1][0], table[1][1], table[1][2]);
	printf("------------- \n");
	printf("  %c | %c | %c \n", table[2][0], table[2][1], table[2][2]);
	printf("\n");
}

//recieves pointer to table, number the user input, and if it is player 1 or 2
void updateBoard(char *tPtr1, char num, int player)
{
	char playerToken = ' ';

	//sets playerToken to X or O depending on player
	if(player == 1)
	{
		playerToken = 'X';
	}
	else
	{
		playerToken = 'O';
	}

	//nested for loop to iterate through the whole 2d array
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//replace number in array with playerToken
			// *((tPtr1 + i*3) + j) i*3 determines the row and j determines the column 
			//checks if character in that cell is equal to the number chosen by user
			if(*((tPtr1 + i*3) + j) == num)
			{
				//sets character in cell equal to the playerToken
				*((tPtr1 + i*3) + j) = playerToken;
			}
		}
	}

	//prints updated game board
	printf("  %c | %c | %c \n", *tPtr1, *((tPtr1) + 1), *((tPtr1) + 2));
	printf("------------- \n");
	printf("  %c | %c | %c \n", *(tPtr1 + 1*3), *((tPtr1 + 1*3) + 1), *((tPtr1 + 1*3) + 2));
	printf("------------- \n");
	printf("  %c | %c | %c \n", *(tPtr1 + 2*3), *((tPtr1 + 2*3) + 1), *((tPtr1 + 2*3) + 2));
	printf("\n");
}

//gets player 1 move
char actionP1()
{
	char num;

	printf("Player 1 (pick an available cell): ");
	//space in front if %c or it will skip next scanf()
	scanf(" %c", &num);
	return num;
}

//gets player 2 move
char actionP2()
{
	char num;

	printf("Player 2 (pick an available cell): ");
	//space in front if %c or it will skip next scanf()
	scanf(" %c", &num);
	return num;
}

int checkWin(char *tPtr2)
{
	for(int i = 0; i < 3; i++)
	{
		//check rows for winner
		
		if(*(tPtr2 + i*3) == *((tPtr2 + i*3) + 1) && *((tPtr2 + i*3) + 1) == *((tPtr2 + i*3) + 2))
		{
			return 0;
		}
		
		//checks columns for winner
		if(*((tPtr2) + i) == *((tPtr2 + 1*3) + i) && *((tPtr2 + 1*3) + i) == *((tPtr2 + 2*3) + i))
		{
			return 0;
		}
		
	}

	//checks diagnol from top left to bottom right
	if(*tPtr2 == *((tPtr2 + 1*3) + 1) && *((tPtr2 + 1*3) + 1) == *((tPtr2 + 2*3) + 2))
	{
		return 0;
	}

	//checks diagnol from top right to bottom left
	if(*((tPtr2) + 2) == *((tPtr2 + 1*3) + 1) && *((tPtr2 + 1*3) + 1) == *(tPtr2 + 2*3))
	{
		return 0;
	}

	return 1;

}

//checks for playing again
int again()
{
	int yOrN = 0;
	printf("Do you want to play again? (0 for yes, 1 for no): ");
	scanf("%d", &yOrN);

	return yOrN;
}

int main()
{
	int playAgain = 0;

	while(playAgain == 0)
	{
		//instantiate 2d array for game board
		char table[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
		//keep count of rounds
		int counter = 0;
		//initiates int used to determine winner to false
		int isDone = 1;

		//prints rules
		printf("To play pick number of cell you want to take.\nPlayer 1 is 'X' and player 2 is 'O'.\nGet 3 of your tokens in a row to win.\n");
		printf("\n");

		board(table);

		while(isDone == 1)
		{
			//player 1 move
			char num = actionP1();
			printf("\n");
			updateBoard(&table[0][0], num, 1);
			counter++;
			isDone = checkWin(&table[0][0]);
			if(isDone == 0)
			{
				break;
			}

			//player 2 move
			num = actionP2();
			printf("\n");
			updateBoard(&table[0][0], num, 2);
			//updates round
			counter++;
			isDone = checkWin(&table[0][0]);
		}

		if(counter%2 == 0)
		{
			printf("Congratulations Player 2! You have won!\n");
		}
		else
		{
			printf("Congratulations Player 1! You have won!\n");
		}

		//checks if user wants to play again
		playAgain = again();
	}

	return 0;

}

