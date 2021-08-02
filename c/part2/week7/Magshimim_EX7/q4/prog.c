#include <stdio.h>
#include <stdlib.h>

#define MENU "Please enter your choice:\n\
1 - Search a term in the document.\n\
2 - change a value in a specific place.\n\
3 - copy a value from one place to another\n\
4 - Exit\n"

#define MAX_STR_LENGTH 64
#define MAX_LINE_LENGTH 512

void printfExit(const char* s);
void getStr(char str[], int size);
void clearBuff();

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printfExit("Usage: prog.exe <csv file path>\n");
	}

	FILE* file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printfExit("Error opening file!\n");
	}

	int choice = 0;

	while (choice != 4)
	{
		printf(MENU);
		(void)scanf("%d", &choice);
		clearBuff();

		if (choice == 1)
		{
			char term[MAX_STR_LENGTH];
			printf("Enter value to search: ");
			getStr(term, MAX_STR_LENGTH);

			fseek(file, 0, SEEK_SET);
			int found = 0;
			int line = 1;
			char buffer[MAX_LINE_LENGTH] = "";
			while (fgets(buffer, MAX_LINE_LENGTH, file))
			{
				if (strstr(buffer, term))
				{
					found = 1;
					break;
				}
				if (strchr(buffer, '\n')) line++;
			}

			if (found)
				printf("Value was found in row %d\n", line);
			else
				printf("Value Wasn't Found\n");
		}
	}

	printf("Goodbye!\n");

	(void)getchar();
	return 0;
}

void printfExit(const char* s)
{
	printf(s);
	exit(-1);
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