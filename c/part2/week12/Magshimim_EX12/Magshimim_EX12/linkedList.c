#include "linkedList.h"

// Function gets a head of a linked list and prints it
void printList(FrameNode* head)
{
	if (head)
	{
		printf("\t%s\t\t\t%d ms\t\t\t\t%s\n", head->frame->name, head->frame->duration, head->frame->path);

		printList(head->next);
	}
}

// Function gets a head of a linked list and a recoursive variable count (needs to be 0 at first) and returns the list's size
int lstlen_util(FrameNode* head, int count)
{
	int len = count;

	if (head)
	{
		len += 1 + lstlen_util(head->next, len);
	}

	return len;
}

// Function gets a head of a linked list and returns the list's size
int lstlen(FrameNode* head)
{
	return lstlen_util(head, 0);
}

// Function get a head of a linked list and a new node, and adds the node to the back of the list
void addframe(FrameNode** head, FrameNode* newNode)
{
	if (!*head)
	{
		*head = newNode;
	}
	else
	{
		FrameNode* p = *head;
		while (p->next)
		{
			p = p->next;
		}
		p->next = newNode;
	}
}

// Function gets a head of a linked list, the node we want the new node to be inserted after, and the new node. and inserts the node after the [after] node
void lstinsertafter(FrameNode** head, FrameNode** after, FrameNode* newNode)
{
	if (!*head)
	{
		printf("function lstinsertafter was given a NULL head");
		exit(-1);
	}
	else
	{
		FrameNode* p = *head;
		while (p != *after && p != NULL)
		{
			p = p->next;
		}

		if (p != NULL)
		{
			newNode->next = p->next;
			p->next = newNode;
		}
		else
		{
			printf("function lstinsertafter was given a non existant [after] argument");
			exit(-1);
		}
	}
}

// Function gets a head of a linked list, the node we want the new node to be inserted after, and the new node. and inserts the node after the [after] node
void lstinsertbefore(FrameNode** head, FrameNode** before, FrameNode* newNode)
{
	if (!*head)
	{
		printf("function lstinsertbefore was given a NULL head");
		exit(-1);
	}
	else if (*head == *before)
	{
		// create a new node after the head
		lstinsertafter(head, head, newNode);

		// replace the second and first nodes
		swapnodes(head, &(*head)->next);
	}
	else
	{
		FrameNode* p = *head;
		while (p->next != *before && p->next != NULL)
		{
			p = p->next;
		}

		if (p->next != NULL)
		{
			newNode->next = p->next;
			p->next = newNode;
		}
		else
		{
			printf("function lstinsertafter was given a non existant [after] argument");
			exit(-1);
		}
	}
}

// Function gets a frame pointer and creates a FrameNode object with the given frame and returns it
FrameNode* newframenode(Frame* frame)
{
	FrameNode* p = (FrameNode*)malloc(sizeof(FrameNode));

	if (p)
	{
		p->next = NULL;
		p->frame = frame;
	}

	return p;
}

// Function gets a name, duration and a path. creates a FrameNode object with the given properties and returns it
FrameNode* newframenode_props(char* name, unsigned int dur, char* path)
{
	FrameNode* p = (FrameNode*)malloc(sizeof(FrameNode));

	if (p)
	{
		p->frame = (Frame*)malloc(sizeof(Frame));

		if (!p->frame) exit(-1);

		p->frame->duration = dur;
		//p->frame->path = "";
		//p->frame->name = "";

		p->next = NULL;
		strcpy(p->frame->name, name);
		strcpy(p->frame->path, path);
	}

	return p;
}

// Function gets a linkedList's head, a name to search and the current step, returns the index (starting from 1) of the node with the same name - if there's one, and 0 otherwise
int searchlist_util(FrameNode* head, char* name, int step)
{
	step++;

	if (head)
	{
		if (!strcmp(head->frame->name, name))
			return step;
		else
			return searchlist_util(head->next, name, step);
	}
	else
		return 0;
}

// Function gets a linkedList's head and a name to search, returns the index+1 of the node with the same name - if there's one, and 0 otherwise
int searchlist(FrameNode* head, char* name)
{
	return searchlist_util(head, name, 0);
}

// Function returns a FrameNode with [name] as it's name if there is one, and NULL else
FrameNode** getnode(FrameNode** head, char* name)
{
	if (*head)
	{
		if (!strcmp((*head)->frame->name, name))
			return head;
		else
			return getnode(&(*head)->next, name);
	}
	else
		return NULL;
}

// Function returns the [index] FrameNode if there is one, and NULL otherwise
FrameNode** getnodeindex(FrameNode** head, unsigned int index)
{
	if (*head && index >= 0 && index < lstlen(*head))
	{
		for (unsigned int i = 0; i < index; i++)
		{
			head = &(*head)->next;
		}

		return head;
	}

	return NULL;
}

// Function returns the previous FrameNode of the FrameNode given as [next] if there is one, and NULL otherwise
FrameNode** getprevnode(FrameNode** head, FrameNode** next)
{
	if (*head && next)
	{
		if ((*head)->next == *next)
			return head;
		else
			return getprevnode(&(*head)->next, next);
	}
	else
		return NULL;
}

// Function gets two nodes and swaps their values
void swapnodes(FrameNode** x, FrameNode** y)
{
	FrameNode* temp = newframenode_props((*x)->frame->name, (*x)->frame->duration, (*x)->frame->path);

	// Swapping the first & second values
	strcpy((*x)->frame->name, (*y)->frame->name);
	(*x)->frame->duration = (*y)->frame->duration;
	strcpy((*x)->frame->path, (*y)->frame->path);

	strcpy((*y)->frame->name, temp->frame->name);
	(*y)->frame->duration = temp->frame->duration;
	strcpy((*y)->frame->path, temp->frame->path);
}

// Function gets a head, two indexes and puts the node that's in the first index in the 2nd index
void changenodeindex(FrameNode** head, unsigned int from, unsigned int to)
{
	if (from == to)
		return;

	FrameNode** f = getnodeindex(head, from);
	FrameNode** t = getnodeindex(head, to);

	swapnodes(f, t);

	changenodeindex(head, from, (from < to) ? to - 1 : to + 1);
}

// Function gets a head of a linked list and a name, and removes the name from the list if it exist, will return 1 if succeed
int lstpop(FrameNode** head, char* name)
{
	FrameNode* p = *getnode(head, name);
	if (p != *head)
	{
		if (p != NULL)
		{
			(*getprevnode(head, p))->next = p->next;
			free(p->frame);
			free(p);

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (lstlen(*head) > 1)
		{
			p = p->next;

			FrameNode* temp = newframenode_props((*head)->frame->name, (*head)->frame->duration, (*head)->frame->path);

			// Swapping the first node's and second node's values
			swapnodes(head, &p);

			// Deleting the 2nd item
			free((*head)->next->frame);
			(*head)->next = p->next;
			free((*head)->next);

			return 1;
		}
		else
		{
			(*head) = NULL;
			return 1;
		}
	}
}

// Function gets a head of a linked list and an index, and removes the indexed node from the list if it exist, will return 1 if succeed
int lstpopindex(FrameNode** head, unsigned int index)
{
	FrameNode* p = *getnodeindex(head, index);
	if (p != *head)
	{
		if (p != NULL)
		{
			(*getprevnode(head, &p))->next = p->next;
			free(p->frame);
			free(p);

			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (lstlen(*head) > 1)
		{
			p = p->next;

			FrameNode* temp = newframenode_props((*head)->frame->name, (*head)->frame->duration, (*head)->frame->path);

			// Swapping the first node's and second node's values
			swapnodes(head, &p);

			/*// Deleting the 2nd item
			free((*head)->next->frame);
			free((*head)->next);
			(*head)->next = p->next;*/

			lstpopindex(head, index + 1);

			return 1;
		}
		else
		{
			(*head) = NULL;
			return 1;
		}
	}
}

// Function gets a head of a linked and two more parameters for the recoursive thingy list and reverse it's order
void reverselist_util(FrameNode** head, FrameNode* previous, FrameNode* current)
{
	if (head)
	{
		if (!current->next)
		{
			*head = current;
			current->next = previous;
			return;
		}

		FrameNode* next = current->next;
		current->next = previous;

		reverselist_util(head, current, next);
	}
}

// Function gets a head of a linked list and reverse it's order
void reverselist(FrameNode** head)
{
	reverselist_util(head, NULL, *head);
}

// Function gets a head of a linked list and returns a pointer to it's last node
FrameNode** getlastnode(FrameNode** head)
{
	if (!*head)
	{
		return NULL;
	}
	else
	{
		if (&(*head)->next == NULL)
		{
			return head;
		}
		else
		{
			return getlastnode(&(*head)->next);
		}
	}
}

// Function gets a head of a linked list and deletes it
void deletelist(FrameNode** head)
{
	FrameNode** node = NULL;

	while ((node = getlastnode(head)) != NULL)
	{
		(*getprevnode(head, node))->next = NULL;
		free((*node)->frame);
		free(*node);
	}
}