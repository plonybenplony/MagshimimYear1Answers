#include <stdio.h>

int main()
{
	int num = 0;
	printf("enter a whole number between 1 and 6\n");
	scanf("%d", &num);
	
	switch (num) {
		case (1):
			printf("one");
			break;
		case (2):
			printf("two");
			break;
		case (3):
			printf("three");
			break;
		case (4):
			printf("four");
			break;
		case (5):
			printf("five");
			break;
		case (6):
			printf("six");
			break;
		default:
			printf("this is not a valid input");
	}
	
	return 0;
}