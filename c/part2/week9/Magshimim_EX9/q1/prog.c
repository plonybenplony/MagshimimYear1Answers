#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 256

int isPalindrome(char str[], int beg, int end);
void getStr(char str[], int size);

int main(void)
{
	char s[MAX_STR_LEN] = "";

	printf("Enter string: ");
	getStr(s, MAX_STR_LEN);

	printf("%s", isPalindrome(s, 0, strlen(s)) ? "Yes, it's a palindrome!" : "Not a palindrome!");

	(void)getchar();
	return 0;
}

int isPalindrome(char str[], int beg, int end)
{
	if (*(str + beg) != *(str + end-1))
		return 0;
	if (beg == end)
		return 1;

	if (end - beg > 2)
		return isPalindrome(str, beg + 1, end - 1);

	return 1;
}

void getStr(char str[], int size)
{
	fgets(str, size, stdin);
	*(str + strcspn(str, "\n")) = '\0';
	*(str + size - 1) = '\0';
}