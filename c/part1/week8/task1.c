#include <stdio.h>

#define SIZE 5
#define TO_PRINT 1

void onesTriangle(int size)
{
	for(int i=0; i<=size; i++)
	{
		for(int j=0; j<i; j++)
		{
			printf("%d", TO_PRINT);
		}
		printf("\n");
	}
}

int main()
{
	int s = SIZE;
	
	onesTriangle(s);
	
	return 0;
}