#include <ctype.h>
#include <stdio.h>

#define SIZE 3

int getch(void);
void ungetch(int);

int getint(int *);

main()
{
	int n, array[SIZE], getint(int *);
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		; /* ������� ��������-������������ */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* �� ����� */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

static char buf[BUFSIZE]; /* ����� ��� ungetch */
static int bufp = 0; /* ����, ��������� ������� � ������ */

int getch(void) /* ����� (�������� ������������) ������ */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int �) /* ������� ������ �� ���� */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: ������� ����� ��������\n");
	else
		buf[bufp++] = �;
}
