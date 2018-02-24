#include <stdio.h> 

void show_two_ss( unsigned int);
unsigned setbits(unsigned int, int, int, unsigned int);

main()
{
	unsigned int x, y; 
	int p, n;
	printf("x: ");
	scanf_s("%d", &x);
	printf("x bin: ");
	show_two_ss(x);
	printf("p: ");
	scanf_s("%d", &p);
	printf("n: ");
	scanf_s("%d", &n);
	printf("y: ");
	scanf_s("%d", &y);
	printf("y bin: ");
	show_two_ss(y);
	printf("\n");

	x = setbits(x, p, n, y); 
	printf("%d\n", x);
	show_two_ss(x);
}

unsigned setbits(unsigned int x, int p, int n, unsigned int y)
{
	return (x & ~(~(~0 << n) << (p + 1 - n))) | ((y&~(~0 << n)) << (p + 1 - n));
}

void show_two_ss(unsigned int A)
{
	int revers = 1;
	int temp = 0;
	int tss_a = 0;
	while (A != 0)
	{
		temp = A % 2;
		tss_a = tss_a + revers * temp;
		A /= 2;
		revers *= 10;
	}
	int temp_tss_a = tss_a;
	int countr = 0;
	while (temp_tss_a != 0)
	{
		temp_tss_a /= 10;
		countr++;
	}
	for (int i = 0; i < 8 - countr; i++)
		printf("0");
	printf("%d\n", tss_a);
}
