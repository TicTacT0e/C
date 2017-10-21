#include <stdio.h> 
#include "C_5.6.h"

main()
{
	char s_str[SIZE];
	char *s = s_str;

	printf("Input str: ");
	input(s);

	//reverse(s);

	//printf("%s\n", s_str);

	printf("%d\n", atoi(s)); 
}