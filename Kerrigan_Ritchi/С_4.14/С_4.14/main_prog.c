#include <stdio.h>

#define SWAP(t, x, y) { t tmp;\
	tmp = y;\
	y = x;\
	x = tmp; }

int main()
{
	int a, b;

	a = 25;
	b = 1;
	SWAP(int, a, b);
	printf("a - %d\nb - %d\n", a, b);
	return 0;
}