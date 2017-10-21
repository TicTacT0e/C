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
		; /* пропуск символов-разделителей */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* не число */
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

static char buf[BUFSIZE]; /* буфер для ungetch */
static int bufp = 0; /* след, свободная позиция в буфере */

int getch(void) /* взять (возможно возвращенный) символ */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int с) /* вернуть символ на ввод */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: слишком много символов\n");
	else
		buf[bufp++] = с;
}
