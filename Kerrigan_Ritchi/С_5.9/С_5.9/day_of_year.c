#include <stdio.h>
#include "C_5.9.h"


int day_of_year(int year, int month, int day)
{
	if (year < 1){
		printf("wrong data ... \n"); return -1;
	}

	if (month > 12 || month < 0) {
		printf("wrong data ... \n"); return -1;
	}

	int i, leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	char *p = daytab[leap]; 

	if (day > *(p + month) || day < 0) {
		printf("wrong data ... \n"); return -1;
	}

	while (month-- > 0)
		day += *p++;
	return day;
}