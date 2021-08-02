/*********************************
* Class: MAGSHIMIM C1			 *
* Week 11          				 *
* Help my array					 *
**********************************/

#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 2

void initArray(int arr[]); // no need for return type because arrays are being sent as memory address so thing can be changed directly
void printGrades(int first, int second);

int main(void)
{
	int myGrades[] = {0,0};
	
	initArray(myGrades); // line 12's explanation
	
	int first = myGrades[0];
	int second = myGrades[1];	
	
	// The original program printed 2686720 or something alike because it's the memory address of the array, arrays can't be easily returned or be used as values in assignments like other variables, thry are stored as the memory address of the first element, and so when you assign int to a array it uses the memory address
	printGrades(first, second);
	return 0;
}

/*
Function will change values of array (input from user)
input: array to change
output: None
*/
void initArray(int arr[]) // line 12's explanation
{
	printf("Enter grades in English and history: ");
	scanf("%d %d", &arr[0], &arr[1]);
}

/*
Function will print two grades
input: the grades to print
output: none
*/
void printGrades(int first, int second)
{
	printf("My grade in English is: %d!\n",first);
	printf("My grade in History is %d! Great Success!\n",second);
}