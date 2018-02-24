#include <stdio.h>

int getint(int *pn)
{
	int c, sign, temp_sign;
	while (isspace(c = getch()))
		; /* пропуск символов-разделителей */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* не число */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		temp_sign = c; 
		c = getch();
		if (!isdigit(c))
		{
			if (c != EOF)
				ungetch(c);
			ungetch(temp_sign);
			return 0; 
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
