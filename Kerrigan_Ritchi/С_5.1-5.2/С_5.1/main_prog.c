#include <stdio.h>
#include "arr.h"

#define SIZE 3

main()
{
	int n; 
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	for (int i = 0; i < SIZE; i++)
		printf("%.3f ", array[i]);
	printf("\n");
}