/*********************************
* Class: MAGSHIMIM C2			 *
* Week 3           				 *
* HW solution   			 	 *
**********************************/
#include <stdio.h>
#include <string.h>

void printArray(char* p, int len)
{
	char* ogp = p; // the original p
	
	for (p; p < ogp + len; p++)
	{
		printf("%c", *p);
	}
	printf("\n");
}

/*
	השגיאה היא בגלל שהתכנה מנסה לגשת אל ערך שאין לה גישה אליו. זה קורה כי
	הלולאה היא לולאה אין סופית כי הלולאה תעצור כשהמשתנה יהיה יותר גדול מעצמו באורך של המחרוזת\
	כמובן שפי לא יכול להיות יותר גדול מעצמו (הוא שווה לעצמו) אז זה אין סופי

	דניאל החניך המתוסכל רוצה להיפגש עם סיגל
	כמעט חרוז
	sigal (I used the last question, the was 2...)
*/

int main(void)
{
	char* msg = "hi jyegq meet me at 2 :)";
	printArray(msg, strlen(msg));

	(void)getchar();
	return 0;
}