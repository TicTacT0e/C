#include <stdio.h>

int getfloat(float *pn)
{
	int c, sign, temp_sign; 
	float frac; 

	while (isspace(c = getch()))
		; 
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c); 
		return 0.0;
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
			return 0.0;
		}
	}
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		getch(c);
	for (frac = 1.0; isdigit(c); c = getch())
	{
		*pn = 10.0 * *pn + (c - '0');
		frac *= 10.0; 
	}
		
	*pn *= sign/frac;
	if (c != EOF)
		ungetch(c);
	return c;
}







