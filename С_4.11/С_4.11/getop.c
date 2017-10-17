#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	i = 0;

	if (islower(c)) //command or name
	{
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) > 1)
			return NAME;
		else
			return c;
	}

	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* �� ����� */

	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}

	if (isdigit(c)) /* ����������� ����� ����� */
	while (isdigit(s[++i] = c = getch()))
		;

	if (c == '.') /* ����������� ������� ����� */
	while (isdigit(s[++i] = c = getch()))
		;
	s[i] = '\0';

	if (c != EOF)
		ungetch(c);
	return NUMBER;
}