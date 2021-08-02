#include <stdio.h>

int main()
{
	int num = 0;
	
	printf("enter a whole number\n");
	scanf("%d", &num);
	
	if (num < 0)
	{
		num *= -1;
	}
	
	printf("the number as a absolute number is: %d\n", num);
	
	return 0;
}