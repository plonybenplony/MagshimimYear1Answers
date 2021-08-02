#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define MAX_NAME_LEN 20

#define EXIT_OPT 7

typedef struct Person
{
	char name[MAX_NAME_LEN];
	int age;

	struct Person* next;
} Person;

void printLine(Person* head);
int listLength(Person* head, int count);
void pushBack(Person** head, Person* newNode);
Person* createEmptyPerson();
Person* createConstPerson(const char* name, int age);
int findPerson(Person* head, char* name, int step);
void searchLine(Person* head);
Person** getPerson(Person** head, char* name);
Person** getPreviousPerson(Person** head, Person** nextP);
void addPerson(Person** head);
void removePerson(Person** head);
void addVIP(Person** head);
void reverseLine(Person** head, Person* previous, Person* current);

void getStr(char str[], int size);
void clearBuff();

void printMenu() { printf("\nWelcome to MagshiParty Line Management Software!\nPlease enter your choice from the following options :\n1 - Print line\n2 - Add person to line\n3 - Remove person from line\n4 - VIP guest\n5 - Search in line\n6 - Reverse line\n7 - Exit\n"); }

int main(void)
{
	// Creating the list
	Person* first = NULL;

	int opt = 0;
	while (opt != EXIT_OPT)
	{
		printMenu();
		(void)scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printLine(first); break;
		case 2:
			addPerson(&first); break;
		case 3:
			removePerson(&first); break;
		case 4:
			addVIP(&first); break;
		case 5:
			searchLine(first); break;
		case 6:
			reverseLine(&first, NULL, first); printf("Line reversed!\n"); break;
		case 7:
			break;
		default:
			printf("Invalid input, please try again\n"); break;
		}
	}

	printf("Goodbye!");

	free(first);
	clearBuff();
	(void)getchar();
	return 0;
}

// Function gets a head of a linked list and prints it
void printList(Person* head)
{
	if (head)
	{
		printf("Name: %s, Age: %d\n", head->name, head->age);

		printList(head->next);
	}
}

// Function gets a head of a linked list and prints it with opening
void printLine(Person* head)
{
	printf("%d people in line:\n", listLength(head, 0));

	printList(head);
}

// Function gets a head of a linked list and a recoursive variable count (needs to be 0 at first) and returns the list size
int listLength(Person* head, int count)
{
	int len = count;

	if (head)
	{
		len += 1 + listLength(head->next, len);
	}

	return len;
}

// Function get a head of a linked list and a new node, and adds the node to the back of the list
void pushBack(Person** head, Person* newNode)
{
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		Person* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}

// Function creates an empty personNode object and returns it // It's an helper function for personNodeConstructor()
Person* createEmptyPerson()
{
	Person* p = (Person*)malloc(sizeof(Person));

	if (p)
		p->next = NULL;

	return p;
}
// Function creates a personNode object with the given values and returns it // It's an helper function for personNodeConstructor()
Person* createConstPerson(const char* name, int age)
{
	Person* p = (Person*)malloc(sizeof(Person));

	if (p)
	{
		p->next = NULL;
		strcpy(p->name, name);
		p->age = age;
	}

	return p;
}

// Function returns 1 if there is a Person with [name] as it's name, and 0 else
int findPerson(Person* head, char* name, int step)
{
	step++;

	if (head)
	{
		if (!strcmp(head->name, name))
			return step;
		else
			return findPerson(head->next, name, step);
	}
	else
		return 0;
}

// Function get a head and prints if the user inputted name exist in the list
void searchLine(Person* head)
{
	char n[MAX_NAME_LEN] = "";
	printf("Enter name to search:\n");
	clearBuff();
	getStr(n, MAX_NAME_LEN);

	if (findPerson(head, n, 0))
		printf("%s found in line\n", n);
	else
		printf("%s not in line\n", n);
}

// Function returns a Person with [name] as it's name if there is one, and NULL else
Person** getPerson(Person** head, char* name)
{
	if (*head)
	{
		if (!strcmp((*head)->name, name))
			return head;
		else
			return getPerson(&(*head)->next, name);
	}
	else
		return NULL;
}

// Function returns the previous Person than the Person with [name] as it's name if there is one, and NULL else
Person** getPreviousPerson(Person** head, Person** nextP)
{
	if (*head && nextP)
	{
		if ((*head)->next == *nextP)
			return head;
		else
			return getPreviousPerson(&(*head)->next, nextP);
	}
	else
		return NULL;
}

// Function returns the first Person with [name] as it's name if there is one, and NULL else
Person** getFirstPerson(Person** head, char* name1, char* name2, char* name3)
{
	int f1 = findPerson(*head, name1, 0);
	if (f1 == 0) f1 = 2147483647;
	int f2 = findPerson(*head, name2, 0);
	if (f2 == 0) f2 = 2147483647;
	int f3 = findPerson(*head, name3, 0);
	if (f3 == 0) f3 = 2147483647;

	int firstest = min(min(f1, f2), f3);

	return (firstest) == f1 ? getPerson(head, name1) : ( (firstest == f2) ? getPerson(head, name2) : getPerson(head, name3) );
}

// Function gets persons details and add him to the given list
void addPerson(Person** head)
{
	printf("Welcome guest!\n");

	Person* newPerson = NULL;

	newPerson = createEmptyPerson();

	clearBuff();

	printf("Enter name: ");
	getStr(newPerson->name, MAX_NAME_LEN);
	printf("Enter age: ");
	(void)scanf("%d", &(newPerson->age));

	// Friends section (there is a much better way of doing that without creating 3 variables, with less code and with more intuitive and dynamic code, but it'll be a bit different for the user (in a good way))
	printf("Enter names of 3 friends:\n");

	char f1[MAX_NAME_LEN] = "";
	char f2[MAX_NAME_LEN] = "";
	char f3[MAX_NAME_LEN] = "";
	clearBuff();
	printf("Friend 1: ");
	getStr(f1, MAX_NAME_LEN);
	printf("Friend 2: ");
	getStr(f2, MAX_NAME_LEN);
	printf("Friend 3: ");
	getStr(f3, MAX_NAME_LEN);

	// Checking if a friend is there and
	Person** friendMaybe = getFirstPerson(head, f1, f2, f3);

	if (friendMaybe != NULL)
	{
		newPerson->next = (*friendMaybe)->next;
		(*friendMaybe)->next = newPerson;
		return;
	}

	// If there are no friends there pushBack
	pushBack(head, newPerson);
}

// Function gets a head of a linked list and a name, and removes the name from the list if it exist, will return success, also it'll print success to the user
void removePersonUtil(Person** head, char* name)
{
	if (!findPerson(*head, name, 0))
	{
		printf("%s not in line\n", name);
		return;
	}

	Person** p = getPerson(head, name);
	if (*p != *head)
	{
		if (p != NULL)
		{
			(*getPreviousPerson(head, p))->next = (*p)->next;

			printf("%s removed from line\n", name);
		}
		else
		{
			printf("%s not in line\n", name);
		}
	}
	else
	{
		if (listLength(*head, 0) > 1)
		{
			p = &(*p)->next;

			Person* temp = createConstPerson((*head)->name, (*head)->age);

			// Swapping the first & second values
			strcpy((*head)->name, (*p)->name);
			(*head)->age = (*p)->age;
			strcpy((*p)->name, temp->name);
			(*p)->age = temp->age;

			// Deleting the 2nd item
			(*head)->next = (*p)->next;
			printf("%s removed from line\n", name);
		}
		else
		{
			(*head) = NULL;
			printf("%s removed from line\n", name);
		}
	}
}

void removePerson(Person** head)
{
	char n[MAX_NAME_LEN] = "";
	clearBuff();
	printf("Enter name to remove:\n");
	getStr(n, MAX_NAME_LEN);

	removePersonUtil(head, n);
}

// Function gets persons details and add him to the top of the given list
void addVIP(Person** head)
{
	printf("VIP GUEST!\n");

	Person* newPerson = NULL;

	newPerson = createEmptyPerson();

	clearBuff();

	printf("Enter name: ");
	getStr(newPerson->name, MAX_NAME_LEN);
	printf("Enter age: ");
	(void)scanf("%d", &(newPerson->age));

	// pushFront
	Person* temp = createConstPerson((*head)->name, (*head)->age);
	temp->next = (*head)->next;

	// Swapping between head and newPerson values (name & age) and pushing newPerson (which now has head's values) to second
	strcpy((*head)->name, newPerson->name);
	(*head)->age = newPerson->age;
	(*head)->next = newPerson;

	strcpy(newPerson->name, temp->name);
	newPerson->age = temp->age;
	newPerson->next = temp->next;
}

// Function gets a head of a linked list and reverse it
void reverseLine(Person** head, Person* previous, Person* current)
{
	if (head)
	{
		if (!current->next)
		{
			*head = current;
			current->next = previous;
			return;
		}

		Person* next = current->next;
		current->next = previous;

		reverseLine(head, current, next);
	}
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