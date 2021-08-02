#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	
	printf("enter the first number ");
	scanf("%d", &x);
	printf("enter the second number ");
	scanf("%d", &y);
	
	//x = 4, y = 32 for GOOD
	/*no, there's no values that will give you no result because the first statement will print if x is EQUAL or BIGGER than y and the 4th
	statement will print if x is SMALLER than y. which means every value will print either M or O */
	
	if (x >= y)
	{
		printf("M");
	}
	if (x*x == y/2)
	{
		printf("G");
	}
	if (x>0 && y<0)
	{
		printf("L");
	}
	if (x<y)
	{
		printf("O");
	}
	if (x*-1 == y)
	{
		printf("A");
	}
	if (x<10&&(y==2||x*y>12))
	{
		printf("O");
	}
	if ((x<17&&x>4)&&(y<10&&y>3)) 
	{
		printf("E");
	}
	if (x)
	{
		printf("D");
	}
	
	return 0;
}