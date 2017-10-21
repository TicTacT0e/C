#include <stdio.h>

#define MAXLINE 1000 

int any(char[], char[]);

main()
{
	char line_1[MAXLINE];
	char line_2[MAXLINE];
	int cntr_1 = 0;
	int cntr_2 = 0;
	char ch;
	int re_num = 0; 

	printf("Enter first line: ");
	for (int i = 0; i < MAXLINE - 1 && (ch = getchar()) != EOF && ch != '\n'; i++, cntr_1++)
		line_1[i] = ch;
	line_1[cntr_1] = '\0';

	printf("Enter second line: ");
	for (int i = 0; i < MAXLINE - 1 && (ch = getchar()) != EOF && ch != '\n'; i++, cntr_2++)
		line_2[i] = ch;
	line_2[cntr_2] = '\0';

	printf("%s\n", line_1);
	printf("%s\n", line_2);

	re_num = any(line_1, line_2);
	printf("%d\n", re_num);
}

int any(char st_1[], char st_2[])
{
	for (int i = 0; st_1[i] != '\0'; i++)
	{
		for (int j = 0; st_2[j] != '\0'; j++)
		{ 
			if (st_1[i] == st_2[j])
			return i;
		}
	}
	return -1;
}
