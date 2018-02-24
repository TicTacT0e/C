#include "stdio.h"
#include "head.h"



int readlines(char *lineptr[], int maxlines)
{
	char line[SIZE]; 
	char *p; 
	int len, nlines; 
	nlines = 0;

	while ((len = getline(line, SIZE)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1; 
		else
		{
			line[len - 1] = '\0'; //убираем символ \n
			strcpy(p, line); 
			lineptr[nlines++] = p; 
		}
	}
	return nlines; 
}

int getline(char s[], int size)
{
	char ch; 
	int i; 
	
	for (i = 0; i < size - 1 && (ch = getchar()) != EOF && ch != '\n'; i++)
		s[i] = ch;
	if (ch == '\n') {
		s[i] = ch;
		++i;
	}
	s[i] = '\0';
	
	return i; 
}