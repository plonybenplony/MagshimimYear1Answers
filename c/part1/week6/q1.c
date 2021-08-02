#include <stdio.h>

int main()
{
	int num = 0;
	
	do
	{
		printf("Please enter number between 1-100: ");
		scanf("%d", &num);
	}
	while(num > 100 || num < 1);
	
	return 0;
}