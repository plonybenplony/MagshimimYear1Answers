#include <stdio.h>

int main()
{
	const int workDaysPerMonth = 20; // change that to 24
	const float workHoursPerDay = 8.5;
	const float salaryPerHour = 32.3; // change that to 8.14364
	
	// calculating the yearly salary using variables
	float yearlySalary = salaryPerHour*workHoursPerDay*workDaysPerMonth*12;
	
	printf("your yearly salary is %.2f shekels.\n", yearlySalary); // change shekels to euros
	
	return 0;
}