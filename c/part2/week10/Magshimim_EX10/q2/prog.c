#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct personNode
{
	char name[MAX_NAME_LEN];
	int age;

	struct personNode* next;
} personNode;


personNode* personNodeConstructor();
void printList(personNode* head);
void pushBack(personNode** head, personNode* newNode);
int listLength(personNode* head, int count);
personNode* copyList(personNode* head);

void getStr(char str[], int size);
void clearBuff();

int main(void)
{
	int length = 0;
	printf("How many people in the list? ");
	(void)scanf("%d", &length);

	personNode* first = (personNode*)NULL;
	personNode* newNode = (personNode*)NULL;

	for (int i = 0; i < length; i++)
	{
		newNode = personNodeConstructor();
		pushBack(&first, newNode);
	}

	printList(first);

	printf("List length: %d\n", listLength(first, 0));

	printf("New list:\n");
	personNode* first2 = copyList(first);
	printList(first2);

	(void)getchar();
	(void)getchar();
	return 0;
}

// Function creates an empty personNode object and returns it // It's an helper function for personNodeConstructor()
personNode* createNewEmptyPerson()
{
	personNode* p = (personNode*)malloc(sizeof(personNode));

	p->next = NULL;

	return p;
}
// Function returns a pointer to a personNode struct, it get it's name and age from the user, and sets next to NULL
personNode* personNodeConstructor()
{
	personNode* p = createNewEmptyPerson();

	clearBuff();
	printf("Enter name: ");
	getStr(p->name, MAX_NAME_LEN);
	printf("Enter age: ");
	scanf("%d", &(p->age));

	return p;
}

// Function gets a head of a linked list and a numeric place (0) and prints it
void printList(personNode* head)
{
	if (head)
	{
		printf("Name: %s, Age: %d\n", head->name, head->age);

		printList(head->next);
	}
}

// Function get a head of a linked list and a new node, and adds the node to the back of the list
void pushBack(personNode** head, personNode* newNode)
{
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		personNode* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}

// Function gets a head of a linked list and a recoursive variable count (needs to be 0 at first) and returns the list size
int listLength(personNode* head, int count)
{
	int len = count;

	if (head)
	{
		len += 1 + listLength(head->next, len);
	}

	return len;
}

// Function gets a lined list head and returns a copy of the list but another one
personNode* copyList(personNode* head)
{
	int len = listLength(head, 0);

	personNode* first = (personNode*)NULL;
	personNode* newNode = (personNode*)NULL;

	personNode* temp = head;

	for (int i = 0; i < len; i++)
	{
		newNode = createNewEmptyPerson();
		strcpy(newNode->name, temp->name);
		newNode->age = temp->age;

		pushBack(&first, newNode);

		temp = temp->next;
	}

	return first;
}

// myFgets with a good name
void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}

// Clears the input buffer
void clearBuff()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}