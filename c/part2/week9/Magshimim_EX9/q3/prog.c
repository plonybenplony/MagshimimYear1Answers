#include <stdio.h>

#define SIDE 8

// upper right
#define REACHED_UR_CORNER x == SIDE-1 && y == 0
// lower right
#define REACHED_LR_CORNER x == SIDE-1 && y == SIDE-1
// lower left
#define REACHED_LL_CORNER x == 0 && y == SIDE-1

#define OUTSIDE_OF_BORDER x >= SIDE || x < 0 || y >= SIDE || y < 0
#define KILL_INSTANCE OUTSIDE_OF_BORDER || board[x][y] != 0

#define PRINT_BOARD_STYLED 0

int horseMoves(int board[SIDE][SIDE], int x, int y, int step, char finLvl[3]);
void printBoard(int board[][SIDE]);

int main(void)
{
	int board[SIDE][SIDE] = { 0 };
	char cornersReached[3] = { 0 };

	if (horseMoves(board, 0, 0, 1, cornersReached))
	{
		printf("Yes, there is a pathfrom 0,0 through all corners! Here it is:\n");
		printBoard(board);
	}
	else
		printf("No Path from 0,0 through all corners\n");

	(void)getchar();
	return 0;
}

int horseMoves(int board[SIDE][SIDE], int x, int y, int step, char finLvl[3])
{
	int result = 0;

	if (REACHED_UR_CORNER)
		finLvl[0]++;
	if (REACHED_LR_CORNER)
		finLvl[1]++;
	if (REACHED_LL_CORNER)
		finLvl[2]++;

	if (finLvl[0] && finLvl[1] && finLvl[2])
	{
		result = 1;
		board[x][y] = step;
	}
	else if (KILL_INSTANCE)
		result = 0;
	else
	{
		board[x][y] = step;
		step++;
		result = horseMoves(board, x + 2, y + 1, step, finLvl) ||
			horseMoves(board, x + 2, y - 1, step, finLvl) ||
			horseMoves(board, x + 1, y + 2, step, finLvl) ||
			horseMoves(board, x + 1, y - 2, step, finLvl) ||
			horseMoves(board, x - 2, y + 1, step, finLvl) ||
			horseMoves(board, x - 2, y - 1, step, finLvl) ||
			horseMoves(board, x - 1, y + 2, step, finLvl) ||
			horseMoves(board, x - 1, y - 2, step, finLvl);

		if (!result)
		{
			board[x][y] = 0;
		}
	}

	return result;
}

/*
Function prints the board
input: board to print
output: none
*/
void printBoard(int board[][SIDE])
{
	int i = 0, j = 0;
	for (i = 0; i < SIDE; i++)
	{
		for (j = 0; j < SIDE; j++)
		{
#if PRINT_BOARD_STYLED
			printf("%c ", board[i][j] == 0 ? '-' : '&');
#else
			printf("%3d", board[i][j]);
#endif
		}
		printf("\n");
	}
}