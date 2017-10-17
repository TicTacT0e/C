#include <stdio.h>

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