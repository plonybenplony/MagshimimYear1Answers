#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
	char mulBoard[WIDTH][HEIGHT] = {0};
	
	// I decided to set the array and print it at the same time, but it's trivial and unimportant to make it in two loops so please don't take this as laziness
	for (int x = 1; x <= WIDTH; x++)
	{
		for (int y = 1; y <= HEIGHT; y++)
		{
			printf("%d\t", x * y);
			mulBoard[x-1][y-1] = x * y;
		}
		printf("\n");
	}
	
	return 0;
}