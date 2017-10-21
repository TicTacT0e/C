#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calc.h"

#define MAXOP 100

main(int argc, char *argv[])
{
	setlocale(LC_ALL, "russian_russia.1251");
	int type;
	double op2;
	double op3;
	char s[MAXOP];
	double dc, cc;

	while (--argc > 0)
	{
		ungetch(*++argv);
		while ((type = getop(s)) != EOF) {
			switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("ошибка: деление на нуль\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					op3 = pop() / op2;
					dc = modf(op3, &cc);
					push(dc * op2);
				}
				else
					printf("ошибка: деление на нуль\n");
				break;
			case NAME:
				mathfunc(s);
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("ошибка: неизвестная операция %s\n", s);
				break;
				return 0;
			}
		}
	}
}


void mathfunc(char s[])
{
	double op2;
	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0)
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("error: unknown command %s\n", s);
}
