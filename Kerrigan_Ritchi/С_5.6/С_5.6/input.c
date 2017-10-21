#include <stdio.h> 
#include "C_5.6.h"

void input(char *str)
{
	int ch;

	while ((ch = getchar()) != EOF && ch != '\n')
		*str++ = ch;
	*str = '\0';
}