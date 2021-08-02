#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

void getStr(char str[], int size);
void clearBuff();


/*
* B
	I malloc-ated 47 bytes in the example,
	it's calculated as - number-of-friends * 4 + the-sum-of-all-friend-name-lengths
*/
int main(void)
{
	int fCount = 0;

	printf("Enter number of friends: ");
	(void)scanf("%d", &fCount);
	clearBuff();

	char** friends = (char**)malloc(sizeof(char*) * fCount);

	printf("%d\n", sizeof(char*));

	// get friends
	{
		char name[MAX_NAME_LENGTH] = { 0 };
		for (int i = 0; i < fCount; i++)
		{
			printf("Enter name of friend %d: ", i + 1);
			getStr(name, MAX_NAME_LENGTH);
			int nl = strlen(name); // To be removed
			friends[i] = (char*)malloc(sizeof(char) * strlen(name));
			strcpy(friends[i], name);
		}
	}

	// reorder friends by abc value
	int change = 1;
	while (change > 0)
	{
		change = 0;
		for (int i = 0; i < fCount - 1; i++)
		{
			int cmp = strcmp(friends[i], friends[i + 1]);

			if (cmp > 0)
			{
				char* temp = friends[i];
				friends[i] = friends[i + 1];
				friends[i + 1] = temp;
				change++;
			}
		}
	}

	// print friends
	for (int i = 0; i < fCount; i++)
	{
		printf("Friend %d: %s\n", i + 1, friends[i]);
	}


	free(friends); // Let them go...

	(void)getchar();
	return 0;
}

void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}

void clearBuff()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}