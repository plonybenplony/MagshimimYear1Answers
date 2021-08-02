#include <stdio.h>

int main(void)
{
	const int MAX_NUM = 10;
	const int MIN_NUM = 1;
	
	// for 'for' loops - i and j are the most meaningful names out there. don't argue
	int i = 0;
	int j = 0;
	
	printf("Daniel Presents: The Board of Multiplication!\n\n");
	
	// Main loop
	for(i = MIN_NUM; i < MAX_NUM+1; i++)
	{	
		// Inner loop
		for(j = MIN_NUM; j < MAX_NUM+1; j++)
			printf("%4d", i * j); // Printing multiplication
		printf("\n"); // newline
	} // End of main loop
	
	// returning 0
	return 0;
}