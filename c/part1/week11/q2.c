#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_FACES 6
#define NUM_OF_TRIES 10000

int main()
{
	// I could use int but I'm trying to save memory
	unsigned short values[NUM_OF_TRIES] = {0};
	unsigned short counters[NUM_OF_FACES] = {0};
	
	srand(time(NULL));
	
	for (int i=0; i<NUM_OF_TRIES; i++)
	{
		values[i] = rand() % NUM_OF_FACES + 1;
		
		counters[values[i] - 1]++;
	}
	
	for (int i=0; i<NUM_OF_FACES; i++)
	{
		printf("number %d has appeared %d times\n", i+1, counters[i]);
	}
	
	return 0;
}