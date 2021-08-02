#include <stdio.h>

int main()
{
	int day = 0;
	int month = 0;
	int year = 0;
	
	// get date
	printf("enter a date with the format of 'dd.mm.yyyy' when d stands for day, m for month and y for year. date should be valid and year must'nt be more than 2017\n");
	scanf("%d.%d.%d", &day, &month, &year);
	
	// check if date is valid
	if (day < 1 || day > 31) {
		printf("day is invalid");
		return 0;
	} if (month < 1 || month > 12) {
		printf("month is invalid");
		return 0;
	} if (year < 1 || year > 2017) {
		printf("year is invalid or greater than 2017");
		return 0;
	}
	
	switch (month) {
		case (1):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (2):
			day++;
			if (day==28+1)
				day = 1;
			else if (day > 29) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (3):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (4):
			day++;
			if (day==30+1)
				day = 1;
			else if (day > 31) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (5):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (6):
			day++;
			if (day==30+1)
				day = 1;
			else if (day > 31) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (7):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (8):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (9):
			day++;
			if (day==30+1)
				day = 1;
			else if (day > 31) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (10):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (11):
			day++;
			if (day==30+1)
				day = 1;
			else if (day > 31) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		case (12):
			day++;
			if (day==31+1)
				day = 1;
			else if (day > 32) {
				printf("day in month is invalid");
				return 0;
			}
			break;
		default:
			printf("month is may be invalid or an error has occured");
			return 0;
			
	}
	if (day==1) {
		month++;
		if (month>12) {
			month = 1;
			year++;
		}
	}
	
	printf("the next day is: %.2d.%.2d.%.2d", day, month, year);
	
	return 0;
}