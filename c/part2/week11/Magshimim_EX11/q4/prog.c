#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode
{
	int val;
	struct IntNode* next;
} IntNode;


void printList(IntNode* list);
void freeList(IntNode* list);
IntNode* printLastNodes(IntNode* head, int k);
void addNode(IntNode** head, int val);

int main(void)
{
	IntNode* list = NULL;
	int length = 0;
	int k = 0;
	printList(list);


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

	printf("Choose a number k, and the k last values will be printed: ");
	(void)scanf("%d", &k);
	(void)getchar();

	printf("The list from that node to the end:\n");
	printLastNodes(list, k);

	(void)getchar();
}

IntNode* printLastNodes(IntNode* head, int k)
{
	int count = 0;
	int length = 0;
	IntNode* p = head;
	IntNode* kNodePtr = NULL;

	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}

	p = head;
	length = count;
	count = 0;

	while (p != NULL)
	{
		if (count > length - k)
		{
			if (count == length - k) { kNodePtr = p; }

			printf("%d ", p->val);
		}

		count++;
		p = p->next;
	}

	return kNodePtr;
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

void freeList(IntNode* list)
{
	// TODO (kal)
}