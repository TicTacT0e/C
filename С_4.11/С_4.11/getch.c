#include <stdio.h>

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