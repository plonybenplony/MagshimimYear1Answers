#include <stdio.h>

int main()
{
	int num = 0;
	int backUpNum = 0;
	int reversedNum = 0;
	
	do
	{
		if (num<0) printf("Invalid input! Positive numbers only.\n");
		printf("Enter number: ");
		scanf("%d", &num);
	}while(num<0);
	
	backUpNum = num;
	
	while(num != 0)
	{
		reversedNum=reversedNum*10 + num%10;
		num /= 10;
	}
	
	printf("Original number: %d\n", backUpNum);
	printf("After reverse: %d\n", reversedNum);
	
	return 0;
}