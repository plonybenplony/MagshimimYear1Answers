#include <stdio.h>

#define COURSES 3 // EXERCISES
#define EXERCISES 11 // COURSES

void printArray(int mat[][COURSES], int rows);

int main()
{
	int myGrades[COURSES][COURSES] = {80, 60, 70};
	
	printArray(myGrades, COURSES);
}

/* Got this array
	80      60      70      0       0       0       0       0       0       0       0
	0       0       0       0       0       0       0       0       0       0       0
	0       0       0       0       0       0       0       0       0       0       0
*/

// I think it had worked for me although it shouldn't have, but the only needed fix i can see is that the array isn't rotated correctly. and i had fixed that by switching between the COURSES and EXERCISES

void printArray(int mat[][COURSES], int rows)
{
	int row = 0;
	int col = 0;
	
	for (row=0; row < rows; row++)
	{
		for (col=0; col < COURSES; col++)
		{
			printf("%d\t", mat[row][col]);
		}
		printf("\n");
	}
}