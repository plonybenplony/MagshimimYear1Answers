#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUB_OPTION "SUB"
#define ADD_OPTION "ADD"


int main(int argc, char** argv)
{
	if (argc < 4)
	{
		printf("ERROR! INVALID NUMBER OF ARGUMENTS!\nHow to use the program: <ADD / SUM> <number> ... <number>");
	}
	else
	{
		if (!strcmp(argv[1], SUB_OPTION))
		{
			int v = atoi(argv[2]);
			for (int i = 3; i < argc; i++)
			{
				v -= atoi(argv[i]);
			}
			printf("Result: %d", v);
		}
		else if (!strcmp(argv[1], ADD_OPTION))
		{
			int v = atoi(argv[2]);
			for (int i = 3; i < argc; i++)
			{
				v += atoi(argv[i]);
			}
			printf("Result: %d", v);
		}
		else
		{
			printf("ERROR! INVALID COMMAND!\nHow to use the program: <ADD / SUM> <number> ... <number>");
		}
	}

	(void)getchar();
	return 0;
}