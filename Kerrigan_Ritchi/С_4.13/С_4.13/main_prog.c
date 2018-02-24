#include <stdio.h> 

#define MAXSIZE 100

void reverse(char[]);

main()
{
	char s[MAXSIZE];
	int i = 0;
	int ch; 
	
	for (i; i < MAXSIZE - 1 && (ch = getchar()) != EOF && ch != '\n'; i++)
		s[i] = ch;
	s[i] = '\0';

	reverse(s);

	printf("%s\n", s);
}

void reverse(char s[])
{
	static int j = 0; 
	static int i = 0; 
	char ch; 

	if ((ch = s[j++]) != '\0')
		reverse(s);

	if (ch != '\0')
		s[i++] = ch; 
	s[i] = '\0';
}