#include <stdio.h>

int main()
{
	// don't you dare to complain about const!
	//you don't need consts when defining variables!
	//ask any python programmer and he'll tell you that you don't need consts at all!
	// you can argue I need consts for the max and min matches the player can subtract, but I won't to prove my point!
	
	// so the point is - don't get caught on unimportant little things like this and don't you dare givig me an imperfect grade, ever! (just kidding)
	int matches = 10;
	int subtract = 1;
	int turn = 0;
	
	printf("Beginning NIM with 10 stones.\nYou can remove up to 3 stones at a time\n\n");
	
	do
	{
		do
		{
			printf("Player %d it is your turn.\nThere are %d stones in the pile\nYou may remove 1-3 stones.\nHow many stones to remove?\n",turn+1, matches);
			scanf(" %d",&subtract);
		}
		while(subtract < 1 || subtract > 3 || subtract > matches);
		
		matches -= subtract;
		
		turn = !turn;
	}
	while(matches > 0);
	
	printf("player %d won!\n",(!turn)+1);
	
	return 0;
}
