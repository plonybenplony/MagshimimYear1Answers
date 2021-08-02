#include <stdio.h>

int main()
{
	int num = 5; // intentionally set to 5, something with the validity check...
	
	do
	{
		if (num < 5 || num > 20) printf("invalid input!\n");
		
		printf("Enter number: ");
		scanf("%d", &num);
	} while(num < 5 || num > 20);
	
	for(int i=1; i<num+1; i++)
	{
		for(int j=1; j<i+1; j++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}