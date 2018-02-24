#include <stdio.h>

#define SIZE 100

void input(char *);
void strcat(char *, char *);
int strend(char *, char *);

main()
{
	char s_str[SIZE]; 
	char *s = s_str;

	char t_str[SIZE];
	char *t = t_str; 

	printf("Enter s_str: ");
	input(s);
	printf("Enter t_str: ");
	input(t); 
	strcat(s, t);
	printf("\nstrcat: "); 
	printf("%s\n", s_str);

	printf("%d\n", strend(s, t)); 
}

int strend(char *s, char *t)
{
	char tmpt = *t; 
	while (*s++)
		;
	while (*t++)
		;
	while (*s == *t)
	{
		s--;
		t--;
	}
	if (tmpt == *++t)
		return 1; 
	else return 0; 
}

void strcat(char *s, char *t)
{
	while (*s++)
		; 
	s--;
	while ((*s++ = *t++) != '\0')
		; 
}

void input(char *str)
{
	int ch; 

	for ( ; (ch = getchar()) != EOF && ch != '\n'; str++)
		*str = ch; 
	*str = '\0';
}