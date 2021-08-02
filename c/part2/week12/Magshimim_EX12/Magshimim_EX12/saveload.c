#include "saveload.h"

// Function gets a head of a linked list and a real path, and saves the list in the path
void saveproj(FrameNode** head, const char* path)
{
	char* listasstr = totext(head);
	FILE* fp = NULL;

	fp = fopen(path, "w");

	fputs(listasstr, fp);

	fclose(fp);
	free(listasstr);
}

// Function gets a head of a linked list and a real path to a saved project, and loads the file to the list
void loadproj(FrameNode** head, const char* path)
{
	char* _name = NULL;
	char* _dur = NULL;
	char* _path = NULL;
	FILE* fp = fopen(path, "r");

	char line[MAX_STR_LEN * 3];
	while (fgets(line, MAX_STR_LEN * 3, fp))
	{
		char* tmp = _strdup(line);

		_name = splitstr(tmp, 0);
		_dur  = splitstr(tmp, 1);
		_path = splitstr(tmp, 2);

		addframe(head, newframenode_props(_name, atoi(_dur), _path));

		free(_name);
		free(_dur);
		free(_path);
		free(tmp);
	}

	fclose(fp);
}

// Functions gets a string and a number and returns the [num] part of the string seprated by [PROJ_SAVE_SEPERATOR]
char* splitstr(char* str, int num)
{
	unsigned sepEnd = (unsigned int)strstr(str, PROJ_SAVE_SEPERATOR) - (unsigned int)str;

	for (unsigned i = 0; i < num; i++)
	{
		str = strstr(str, PROJ_SAVE_SEPERATOR) + 1;
		sepEnd = (unsigned)strstr(str, PROJ_SAVE_SEPERATOR) - (unsigned)str;
	}

	return substr(str, 0, sepEnd);
}

// Function gets a head of a linked list and returns a dynamically allocated string representing the given list
char* totext(FrameNode** head)
{
	char* text = malloc(sizeof(char) * 1);
	char* buff = malloc(sizeof(char) * 1);
	*text = '\0';
	FrameNode* node = *head;

	while (node)
	{
		// Putting the formatted node properties in [buff];
		unsigned int size = sizeof(char) * (strlen(node->frame->name) + 1) +
			sizeof(char) * (intlen(node->frame->duration) + 1) +
			sizeof(char) * (strlen(node->frame->path) + 1) +
			sizeof(char) * 2;
		buff = realloc(buff, size);
		sprintf(buff, "%s%s%d%s%s%s",
			node->frame->name, PROJ_SAVE_SEPERATOR,
			node->frame->duration, PROJ_SAVE_SEPERATOR,
			node->frame->path, PROJ_SAVE_SEPERATOR_NEWLINE);

		// Adding [buff] to [text], also changing [text]'s size to fit the new content
		strcat_heap(&text, buff);

		// Going one node forward
		node = node->next;
	}

	free(buff);

	return text;
}

// ------------------------Utility functions needed for this file------------------------

// Function gets a string and returns a new string from index [beg] to index [end] in the new string
char* substr(const char* str, int beg, int end)
{
	int len = end - beg;

	char* dest = (char*)malloc(sizeof(char) * (len + 1));

	for (int i = beg; i < end && (*(str + i) != '\0'); i++)
	{
		*dest = *(str + i);
		dest++;
	}

	if (dest)
		*dest = '\0';

	return dest - len;
}

// Functions takes two c strings ([dest] has to be on the heap), and adds the second string to the first one, it's also reallocating memory
void strcat_heap(char** dest, const char* src)
{
	int size = strlen(*dest) + strlen(src) + 1;
	char* tmp = realloc(*dest, size);
	if (!tmp) exit(-1);

	strcpy(tmp, *dest);
	strcat(tmp, src);

	*dest = tmp;
}

// Function get an int and returns it's length is it was a string (8 - 1, 27 - 2, 159 - 3)
unsigned int intlen(int n)
{
	unsigned int count = 0;

	if (n == 0) return 1;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}