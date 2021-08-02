#include <stdio.h>

#define ARRAY_LENGTH 5

void reverseArray(int numbers[]);

int main()
{
	int numbers[ARRAY_LENGTH] = {0};
	
	printf("Enter %d numbers to array: ", ARRAY_LENGTH);
	for (int i=0; i<ARRAY_LENGTH; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	reverseArray(numbers);
	
	printf("Array reversed: ");
	for (int i=0; i<ARRAY_LENGTH; i++)
	{
		printf("%d ", numbers[i]);
	}
	
	return 0;
}

void reverseArray(int numbers[])
{
	int oldNumbers[ARRAY_LENGTH] = 
	{
		numbers[0], numbers[1], numbers[2], numbers[3], numbers[4],
	};
	
	for (int i=0; i<ARRAY_LENGTH; i++)
	{
		numbers[i] = oldNumbers[ARRAY_LENGTH - i - 1];
	}
}