#include <stdio.h>

int main()
{
	int sum = 0;
	
	for(int i=1; i<100; i++)
	{
		if (i%3==0)
		{
			sum += i;
		}
	}
	
	printf("The sum of all the numbers between 1-100 that can be divided by 3 is: %d", sum);
	
	return 0;
}