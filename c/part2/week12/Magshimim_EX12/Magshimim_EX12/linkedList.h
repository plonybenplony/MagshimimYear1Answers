#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 64

#define FALSE 0
#define TRUE !FALSE

// Frame struct
typedef struct Frame
{
	char name[MAX_STR_LEN];
	unsigned int duration;
	char path[MAX_STR_LEN];
} Frame;


// Link (node) struct
typedef struct FrameNode
{
	Frame* frame;
	struct FrameNode* next;
} FrameNode;


// Function gets a head of a linked list and prints it
void printList(FrameNode* head);

// Function gets a head of a linked list and returns the list's size
int lstlen(FrameNode* head);

// Function get a head of a linked list and a new node, and adds the node to the back of the list
void addframe(FrameNode** head, FrameNode* newNode);

// Function gets a head of a linked list, the node we want the new node to be inserted after, and the new node. and inserts the node after the [after] node
void lstinsertafter(FrameNode** head, FrameNode** after, FrameNode* newNode);

// Function gets a head of a linked list, the node we want the new node to be inserted after, and the new node. and inserts the node after the [after] node
void lstinsertbefore(FrameNode** head, FrameNode** before, FrameNode* newNode);

// Function gets a frame pointer and creates a FrameNode object with the given frame and returns it
FrameNode* newframenode(Frame* frame);

// Function gets a name, duration and a path. creates a FrameNode object with the given properties and returns it
FrameNode* newframenode_props(char* name, unsigned int dur, char* path);

// Function gets a linkedList's head and a name to search, returns the index of the node with the same name - if there's one, and 0 otherwise
int searchlist(FrameNode* head, char* name);

// Function returns a FrameNode with [name] as it's name if there is one, and NULL else
FrameNode** getnode(FrameNode** head, char* name);

// Function returns the [index] FrameNode if there is one, and NULL otherwise
FrameNode** getnodeindex(FrameNode** head, unsigned int index);

// Function returns the previous FrameNode of the FrameNode given as [next] if there is one, and NULL otherwise
FrameNode** getprevnode(FrameNode** head, FrameNode** next);

// Function gets two nodes and swaps their values
void swapnodes(FrameNode** x, FrameNode** y);

// Function gets a head, two indexes and puts the node that's in the first index in the 2nd index
void changenodeindex(FrameNode** head, unsigned int from, unsigned int to);

// Function gets a head of a linked list and a name, and removes the name from the list if it exist, will return 1 if succeed
int lstpop(FrameNode** head, char* name);

// Function gets a head of a linked list and an index, and removes the indexed node from the list if it exist, will return 1 if succeed
int lstpopindex(FrameNode** head, unsigned int index);

// Function gets a head of a linked list and reverse it's order
void reverselist(FrameNode** head);

// Function gets a head of a linked list and returns a pointer to it's last node
FrameNode** getlastnode(FrameNode** head);

// Function gets a head of a linked list and deletes it
void deletelist(FrameNode** head);

#endif
