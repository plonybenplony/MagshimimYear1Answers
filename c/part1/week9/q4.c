#include <stdio.h>

enum month
{
	january=1, febuary, march, april, may, june, july, august, september, october, november, december
};

enum day
{
	sun=1, mon, tue, wed, thu, fri, sat
};

int checkInput(enum month m, int d);
enum day dayInAWeek(enum month m, int d, enum day wd);

int main()
{
	printf("Hello! Welcome to the day calculator!\n");
	
	enum month m = 0;
	int d = 0;
	enum day wd = 0;
	
	do
	{
		printf("Enter month to check: (1-Jan, 2-Feb, etc) ");
		scanf("%d", &m);
		printf("Enter day to check: ");
		scanf("%d", &d);
	}
	while(!checkInput(m, d));
	
	do
	{
		printf("Enter the weekday of the 1st of the month: (1-Sunday, 2-Monday, etc) ");
		scanf("%d", &wd);
	}
	while(wd < 1 || wd > 7);
	
	printf("The %d.%d will be a ", d, m);
	
	dayInAWeek(m, d, wd);
	
	return 0;
}

int checkInput(enum month m, int d)
{
	if (m < 1 || m > 12)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (d < 1)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == january && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == febuary && d > 28)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == march && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == april && d > 30)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == may && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == june && d > 30)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == july && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == august && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == september && d > 30)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == october && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == november && d > 30)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	if (m == december && d > 31)
	{
		printf("Invalid input, try again\n");
		return 0;
	}
	
	return 1;
}

enum day dayInAWeek(enum month m, int d, enum day wd)
{
	int addToDay = wd - 1;
	enum day weekDayOfD = d % 7 + addToDay;
	
	switch (weekDayOfD)
	{
		case 1:
			printf("Sunday");
			break;
		case 2:
			printf("Monday");
			break;
		case 3:
			printf("Tuesday");
			break;
		case 4:
			printf("Wednesday");
			break;
		case 5:
			printf("Thursday");
			break;
		case 6:
			printf("Friday");
			break;
		case 7:
			printf("Saturday");
			break;
	}
}








