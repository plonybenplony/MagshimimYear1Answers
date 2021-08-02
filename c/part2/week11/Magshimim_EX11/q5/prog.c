#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


void printList(IntNode* list);
void rotateList(IntNode** head, int k);
void addNode(IntNode** head, int val);

/*
In my very creative solution, except for when checking the length of the list in a temporary, I don't change the ->next of a node ever :)
*/

int main(void)
{
	IntNode* list = NULL;
	int length = 0;
	int k = 0;
	
	
	printf("How many nodes in list? ");
	(void)scanf("%d", &length);
	(void)getchar();

	for (int i = 0, v = 0; i < length; i++)
	{
		printf("Enter number: ");
		(void)scanf("%d", &v);
		(void)getchar();

		addNode(&list, v);
	}

	printf("Choose a number k, and the list will be rotated k places to the left: ");
	(void)scanf("%d", &k);
	(void)getchar();

	rotateList(&list, k);

	printList(list);
	
	(void)getchar();
}

void changenodeindex(IntNode** head, unsigned int from, unsigned int to);

void rotateList(IntNode** head, int k)
{
	int length = 0;

	IntNode* p = *head;
	while (p)
	{
		length++;
		p = p->next;
	}

	for (int i = 0; i < k; i++)
	{
		changenodeindex(head, 0, length-1);
	}
}

IntNode** getNode(IntNode** head, int index)
{
	int count = 0;
	IntNode* p = *head;

	if (index == 0) return head;

	while (p)
	{
		if (count == index)
			return &p;

		count++;
		p = p->next;
	}

	return NULL;
}

void changenodeindex(IntNode** head, unsigned int from, unsigned int to)
{
	if (from == to)
		return;

	IntNode** f = getNode(head, from);
	IntNode** t = getNode(head, to);

	int val = (*f)->val;
	(*f)->val = (*t)->val;
	(*t)->val = val;

	changenodeindex(head, from, (from < to) ? to - 1 : to + 1);
}

void addNode(IntNode** head, int val)
{
	IntNode* node = malloc(sizeof(IntNode));

	node->next = NULL;
	node->val = val;

	if (*head == NULL)
	{
		*head = node;
		return;
	}

	IntNode* p = *head;

	while (p->next != NULL)
	{
		p = p->next;
	}

	p->next = node;
}

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