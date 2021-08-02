#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 10

int main()
{
	char name[STR_LEN] = { 0 };
	printf("Please enter your name.\n");
	fgets(name, STR_LEN, stdin);
	
	for(int i=0; i<STR_LEN; i++)
	{
		if (!name[i])
		{
			break;
		}
		if (name[i] == '\n')
		{
			name[i] == '\0';
			break;
		}
	}
	
	//printf("Your name is %s\n", name[0]);
	printf("Your name is %s", name);
	
	return 0;
}