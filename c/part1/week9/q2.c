#include <stdio.h>

enum difficultyLevel
{
	trivial=1, easy, normal, hard, impossible
};

int main()
{
	enum difficultyLevel diff = 0;
	printf("Choose a difficulty level (You can choose between 1-5)\n");
	scanf("%d", &diff);
	
	printf("%d", diff);
	
	return 0;
}

/*
היתרון בשימוש באנאם הוא שיש ביטוי מילולי למספרים ולא רק 1 או אפס אלא ממש מילים

אפשר פשוט לכתוב לאפשרות הראשונה =1 כמו שעשיתי למעלה והתכנה תדע להעלות גם את האחרים בתגובה
*/