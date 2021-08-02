#include <stdio.h>

int main()
{
	int firstNum = 0;
	int secondNum = 0;
	int thirdNum = 0;
	
	printf("Enter 3 whole numbers:\n");
	
	// getting the numbers from the user
	scanf("%d %d %d", &firstNum, &secondNum, &thirdNum);
	
	// claculating the avrage of the three inputed numbers
	float avrage = (firstNum + secondNum + thirdNum)/3.0;
	
	printf("the avrage is: %.3f", avrage);
	
	return 0;
}