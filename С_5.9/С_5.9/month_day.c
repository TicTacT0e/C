#include <stdio.h>
#include "C_5.9.h"


void month_day(int year, int yearday, int *pmonth, int *pday)
{
	if (year < 1 || yearday < 1)
	{
		printf("Error...\n");
		*pmonth = -1;
		*pday = -1;
		return;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (leap == 1 && yearday > 366)
	{
		printf("Error...\n");
		*pmonth = -1;
		*pday = -1;
		return;
	}
	if (leap == 0 && yearday > 365)
	{
		printf("Error...\n");
		*pmonth = -1;
		*pday = -1;
		return;
	}

	char *p = daytab[leap];
	char *tmp = p; 
	
	while (yearday > *p)
	{
		yearday -= *p++;
	}
	*pmonth = p - tmp; 
	*pday = yearday; 

}