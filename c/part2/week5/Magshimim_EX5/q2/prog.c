#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 5
#define MAX_VAL 75

#define FALSE 0
#define TRUE !FALSE

#define HIT 'X'

#define STR_LEN 20
#define NO_WINNER -1

typedef struct bingoPlayer
{
	char name[STR_LEN];
	char board[BOARD_SIZE][BOARD_SIZE];
} bingoPlayer;

typedef struct bingoGame
{
	int* numsDrawn;
	int numOfNumsDrawn;
	bingoPlayer* players;
	int numPlayers;
} bingoGame;

void initGame(bingoGame* game, int players);
void initBingoPlayer(bingoPlayer* pPlayer);
int updateGame(bingoGame* game, int num);
int numInArr(char arr[][BOARD_SIZE], int num);
void updateBoard(bingoPlayer* player, int num);
void printBoard(bingoPlayer player);
void printBoards(bingoGame game);
int hasWon(bingoPlayer player);
void myFgets(char str[], int n);

int main(void)
{
	int numPlayers = 0;
	int winner = NO_WINNER;
	int drawnAlready = TRUE;
	int num = 0;
	bingoGame game = { 0, 0, 0, 0 };

	srand((unsigned int)time(NULL));

	printf("How many players? ");
	(void)scanf("%d", &numPlayers);
	(void)getchar(); // clean buffer

	initGame(&game, numPlayers);

	printBoards(game);

	while (winner == NO_WINNER)
	{
		while (drawnAlready)
		{
			num = (rand() % MAX_VAL) + 1;
			drawnAlready = FALSE;
			for (int i = 0; i < game.numOfNumsDrawn; i++)
			{
				drawnAlready = drawnAlready || (num == game.numsDrawn[i]);
			}
		}
		// num now contains a new drawn number!
		winner = updateGame(&game, num);
		drawnAlready = TRUE;
	}
	printf("%s won the match! The winning board:\n", game.players[winner].name);
	printBoard(game.players[winner]);

	(void)getchar();
	return 0;
}

/*
Function inits a bingo game
input: game and number of players
output: none
*/
void initGame(bingoGame* game, int players)
{
	game->numOfNumsDrawn = 0;
	game->numPlayers = 0;
	game->numsDrawn = 0;
	game->players = NULL;

	int i = 0;
	game->numsDrawn = (int*)malloc(sizeof(int) * 0); //no nums drawn yet...realloc will be used later
	game->numPlayers = players;
	game->players = (bingoPlayer*)malloc(sizeof(bingoPlayer) * players);
	for (i = 0; i < game->numPlayers; i++)
	{
		initBingoPlayer(&(game->players[i]));
	}
}

/*
This function initializes bingoPlayer struct
Input: pointer to bingoPlayer struct
Output: None
*/
void initBingoPlayer(bingoPlayer* pPlayer)
{
	strcpy(pPlayer->name, "Daniel");

	int num = 0;

	printf("What is the player's name?\n");
	myFgets(pPlayer->name, STR_LEN);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			pPlayer->board[i][j] = 0;
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			num = (rand() % MAX_VAL) + 1;

			while (numInArr(pPlayer->board, num))
			{
				num = (rand() % MAX_VAL) + 1;
			}

			pPlayer->board[i][j] = (char)num;
		}
	}
}

/*
This function checks if a number is in an array
returns 1 if it is and 0 otherwise
Input: char array, int - number
Output: 1 - num in array, 0 - otherwise
*/
int numInArr(char arr[][BOARD_SIZE], int num)
{
	int i = 0, j = 0;
	int found = FALSE;

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if ((int)arr[i][j] == num)
			{
				found = TRUE;
				i = BOARD_SIZE;
				break;
			}
		}
	}
	return found;
}

/*
This functions updates a board - this includes adding the number drawn to the array of the numbers.
Also, updating all players' boards
input: game and the number drawn
output: index of player who won, or -1 if no winner yet
*/
int updateGame(bingoGame* game, int num)
{
	int winner = NO_WINNER;

	game->numOfNumsDrawn++;
	game->numsDrawn = (int*)realloc(game->numsDrawn, sizeof(int) * game->numOfNumsDrawn);
	game->numsDrawn[game->numOfNumsDrawn - 1] = num;

	for (int i = 0; i < game->numPlayers; i++)
	{
		updateBoard(&(game->players[i]), num);
		if (hasWon(game->players[i]))
		{
			winner = i;
		}
	}

	return winner;
}


/* This function updates the player details
It
and checks if this number is in the player board, if it is, it switches the place in the board to 'X'
Input: bingoPlayer struct pointer and number randomized
Output: None
*/
void updateBoard(bingoPlayer* player, int num)
{
	int i = 0, j = 0;

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if ((int)player->board[i][j] == num)
			{
				player->board[i][j] = HIT;
			}
		}
	}
}

/* This function prints a player board
Input: bingoPlayer
Output: None
*/
void printBoard(bingoPlayer player)
{
	int i = 0, j = 0;

	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			if (player.board[i][j] == HIT)
			{
				printf(" X  ");
			}
			else
			{
				printf(" %2d ", (int)player.board[i][j]);
			}
		}
		printf("\n\n");
	}
}

/*
This function prints all players' boards
Input: bingoPlayer
Output: None
*/
void printBoards(bingoGame game)
{
	for (int i = 0; i < game.numPlayers; i++)
	{
		printf("%s's board:\n", game.players[i].name);
		printBoard(game.players[i]);
	}
}


/* This function checks if a player has won (got a row of HITS)
Input: bingo Player
Output: int - 1 if won, 0 otherwise
*/
int hasWon(bingoPlayer player)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		// Vertical
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (player.board[i][j] != HIT)
				break;
			else if (j == BOARD_SIZE - 1)
				return TRUE;
		}

		// Horizontal
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (player.board[j][i] != HIT)
				break;
			else if (j == BOARD_SIZE - 1)
				return TRUE;
		}
	}

	return FALSE;
}



/*
Function will perform the fgets command and also remove the newline
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
*/
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}