#include <stdio.h>
#include "C_5.9.h"
#include <locale.h>

main()
{
	setlocale(LC_ALL, "rus");

	///DAY_OF_YEAR
	/*int year, month, day;

	printf("Enter year: ");
	scanf_s("%d", &year);
	printf("Enter month: ");
	scanf_s("%d", &month);
	printf("Enter day: ");
	scanf_s("%d", &day);


	int yearday = day_of_year(year, month, day);
	printf("Day of year: %d\n", yearday);*/

	///MONTH_DAY
	int year, yearday;
	int month, day;

	printf("Enter year: ");
	scanf_s("%d", &year);
	printf("Enter yearday: ");
	scanf_s("%d", &yearday);

	month_day(year, yearday, &month, &day);
	printf("Month and day: %d %d\n", month, day);
}