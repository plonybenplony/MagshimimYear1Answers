#include <stdio.h>

int main()
{
	int age = 0;
	int height = 0;
	
	printf("enter age and height as whole numbers\n");
	scanf("%d %d", &age, &height);
	printf("\n\n");
	
	if (age < 15 && height > 175) {
		printf("You should play basketball\n");
	}
	else if (height > 185 && age >= 15) {
		printf("You should play basketball!\n");

	} else if (age >= 15) {
		printf("Are you a soccer player?\n");
	}
	
	return 0;
}