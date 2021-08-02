#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


void printList(IntNode* list);
void freeList(IntNode* list);

int main(void)
{
	IntNode* list = NULL;
	printList(list);


	// TODO: HW


	(void)getchar();
	return 0;
}

IntNode* concatenate(IntNode* a, IntNode* b)
{
	IntNode* last = NULL;

	if (a == NULL && b != NULL) { return b; }
	if (b == NULL && a != NULL) { return a; }
	if (a == NULL && b == NULL) { return NULL; }

	last = a;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = b;

	return a;
}

//************************************
// Method:    printList
// Returns:   void
// Description: prints list recursively
// Parameter: IntNode * list
//************************************
void printList(IntNode* list)
{
	if (list)
	{
		printf("%d  ", list->val);
		printList(list->next);
	}
	else
	{
		printf("\n");
	}
}

//************************************
// Method:    freeList
// Returns:   void
// Description: Frees list (recursively?)
// Parameter: intNode * list
//************************************
void freeList(IntNode* list)
{
	// TODO (kal)
}