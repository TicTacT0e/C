#include <stdio.h>
#include "calc.h""

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("������: ���� �����, %g �� ����������\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("������: ���� ����\n");
		return 0.0;
	}
}