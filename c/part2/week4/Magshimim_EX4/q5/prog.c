/*********************************
* Class: MAGSHIMIM C2			 *
* Week 4           				 *
* HW solution   			 	 *
**********************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int* createArr(int len);

int main(void)
{
	int size = 0;
	int* pArr = 0;

	printf("Enter a number of cells: ");
	(void)scanf("%d", &size);
	pArr = createArr(size);
	printf("The array is at address %p: ", pArr);
	free(pArr);

	(void)getchar();
	(void)getchar();
	return 0;
}

/*
I didn't find any memory leaks, but there was an extra free()


 * First issue(s) is that scanf takes a pointer
and the value is given, so we need to '&' before the size

 * Second problem is in line 54 there's an attempt to free i
which is an integer, not a pointer so there's an error there

 * Third problem is that when we use malloc we need to multiply the amount of cells
by the sizeof the used variable type, is this case int

 * Fourth issue is with the for loop in createArr, we get the number into
size which is the size of the array, this gives us some unexcepcted behaviour,
we need to get it into the i cell in pArr.

A smaller problem is that the explanation of createArr function
is not complete, the function also populates the array.
*/


/*
Function creates an array and populates it
input: number of cells in the array
output: pointer to the new array
*/
int* createArr(int size)
{
	int* pArr = (int*)malloc(size * sizeof(int));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("Please enter a number for index %d: ", i);
		(void)scanf("%d", pArr + i);
	}
	return pArr;
}