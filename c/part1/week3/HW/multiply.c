#include <stdio.h>

int main()
{
	int intNum = 16;
	float floatNum = 5.125;
	
	//I multiply the numbers inside a float so the result will be calculated as float
	float mul = floatNum * intNum;
	
	//printing the variable mul with 2 numbers after the dot
	printf("the result of the multiplication is: %.2f\n", mul);
	
	return 0;
}