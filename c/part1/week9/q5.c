/*********************************
* Class: MAGSHIMIM C1			 *
* Week 8           				 *
**********************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int areValidNumbers(int num1,int num2, int num3);


int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;	 
	
	do
	{
		num1 = rand() % 100;
		num2 = rand() % 100;
		num3 = rand() % 100;
	}
	while(areValidNumbers(num1, num2, num3));
	
	printf("%d %d %d", num1, num2, num3);
	
	return 0;
}

/*
	A function to check if one of the numbers give one is even, one is uneven and one is above 50
	Input: 3 random numbers between 0 - 100
	Output: 0/1 if one is even, one is uneven and one is above 50
*/
int areValidNumbers(int num1, int num2, int num3)
{
	int ans = 0;
    
	if (num1 % 2 == 0 || num3 % 2 == 0 || num2 % 2 == 0)
		ans = ans; // pass
	else
		ans = 1;
	if (num1 % 2 == 1 || num3 % 2 == 1 || num2 % 2 == 1)
		ans = ans; // pass
	else
		ans = 1;
	if (num1 > 50 || num3 > 50 || num2 > 50)
		ans = ans; // pass
	else
		ans = 1;
	
	
	return ans;
}





