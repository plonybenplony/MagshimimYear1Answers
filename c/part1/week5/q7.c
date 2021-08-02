#include <stdio.h>

int main()
{
	const int MINAGE = 16;
	const int MAXAGE = 18;
	int age = 0;
	
	printf("Please enter an age: \n");
	scanf("%d", &age);
	getchar(); // cleaning the buffer
	if (!(age >= MINAGE && age <= MAXAGE)) {
		printf("Yay! your age is not between 16 and 18!\n");
		printf("You can have a phone!\n");
	} else {
		printf("Sorry, no phone for you...\n");
	}
	
	return 0;
}