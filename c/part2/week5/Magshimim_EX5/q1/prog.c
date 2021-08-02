#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRO_OP 1
#define CON_OP 2
#define PRINT_OP 3
#define EXIT_OP 4

#define STR_LEN 50
#define MAX_LIST_LENGTH 10

typedef struct reasonList
{
	char* listName;
	char* reasons[MAX_LIST_LENGTH];
	int numReasons;
} reasonList;


void initList(reasonList* list, char* name);
void addReason(reasonList* list);
void printList(reasonList list);
int menu(void);
void myFgets(char str[], int n);
void deleteList(reasonList* list);

int main(void)
{
	char dillema[STR_LEN] = { 0 };
	int op = 0;

	reasonList proList;
	initList(&proList, "PRO");
	reasonList conList;
	initList(&conList, "CON");

	printf("What is your dillema?\n");
	myFgets(dillema, STR_LEN);

	while (op != EXIT_OP)
	{
		op = menu();

		switch (op)
		{
		case(PRO_OP):
			addReason(&proList);
			break;
		case(CON_OP):
			addReason(&conList);
			break;
		case(PRINT_OP):
			printf("Your dillema:\n");
			printf("%s\n\n", dillema);

			printList(proList);
			printList(conList);
			break;
		case(EXIT_OP):
			deleteList(&proList);
			deleteList(&conList);
			break;
		}
	}

	printf("Good luck!\n");
	(void)getchar();
	return 0;
}

/*
Function will initialize a reason list
input: the list to init, and its name
output: none
*/
void initList(reasonList* list, char* listName)
{
	list->listName = (char*)malloc(STR_LEN * sizeof(char));

	strcpy(list->listName, listName); // Name
	list->numReasons = 0; // Count
}

/*
Function will add a reason to the list
input: the list to add to and its name
output: none
*/
void addReason(reasonList* list)
{
	list->numReasons++;
	list->reasons[list->numReasons-1] = (char*)malloc(STR_LEN * sizeof(char));

	printf("Enter a reason to add to list %s:\n", list->listName);
	myFgets(list->reasons[list->numReasons - 1], STR_LEN);
}

/*
Function will print a list of reasons
input: the list
output: none
*/
void printList(reasonList list)
{
	printf("List %s\n---------\n", list.listName);

	for (int i = 0; i < list.numReasons; i++)
	{
		printf("%s\n", list.reasons[i]);
	}

	printf("\n");
}

/*
Function shows menu and returns user's choice
input: none
output: user's choice
*/
int menu(void)
{
	int op = 0;
	printf("Choose option:\n");
	printf("%d - Add PRO reason\n", PRO_OP);
	printf("%d - Add CON reason\n", CON_OP);
	printf("%d - Print reasons\n", PRINT_OP);
	printf("%d - Exit\n", EXIT_OP);
	(void)scanf("%d", &op);

	while (op < PRO_OP || op > EXIT_OP)
	{
		printf("Invalid option. Try again: ");
		(void)scanf("%d", &op);
	}

	(void)getchar(); // clean buffer
	return op;
}

/*
Function will delete a list
input: the list to delete
output: none
*/
void deleteList(reasonList* list)
{
	free(list->listName);

	for (int i = 0; i < list->numReasons; i++)
	{
		free(list->reasons[i]);
	}
}

/*
Function will perform the fgets command and also remove the newline
that might be at the end of the string - a known issue with fgets.
input: the buffer to read into, the number of chars to read
*/
void myFgets(char str[], int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}