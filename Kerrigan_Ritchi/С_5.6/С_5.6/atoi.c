#include <stdio.h> 
#include "C_5.6.h"

/*Преобразование в число*/


int atoi(char *s)
{
	int sign;
	int n = 0; 

	for (; isspace(*s); s++)
		;

	sign = (*s == '-') ? -1 : 1; 

	if (*s == '+' || *s == '-')
		s++; 

	for (; isdigit(*s); s++)
		n = n * 10 + (*s - '0');

	return n * sign; 
}