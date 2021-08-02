#include <stdio.h>
#include <stdbool.h>

int main()
{
	int x = 0;
	
	bool aleph = 1==2 || 2==3; // א
	bool beit = x != x; // ב
	bool gimel = 1; // ג
	bool dalet = x != x && x == x; // ד
	
	printf("a - %d, b - %d, c - %d, d - %d", aleph, beit, gimel, dalet);
	
	return 0;
}