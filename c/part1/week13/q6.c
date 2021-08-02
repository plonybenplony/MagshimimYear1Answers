#include <stdio.h>

#define WIDTH 10
#define HEIGHT 8

void printArray(char mat[][WIDTH], int rows);

int main()
{
	char drawing[HEIGHT][WIDTH] = {
		"          ",
		"          ",
		"  #    #  ",
		"          ",
		"          ",
		" *       *",
		"   * * *  ",
		"          "
	};
	
	printArray(drawing, HEIGHT);
}

void printArray(char mat[][WIDTH], int rows)
{
	int row = 0;
	int col = 0;
	
	for (row=0; row < rows; row++)
	{
		for (col=0; col < WIDTH; col++)
		{
			printf("%c", mat[row][col]);
		}
		printf("\n");
	}
}