#include <stdio.h>

#define MAXLINE 1000

void squeeze(char[], char[]);

main()
{
	char line_1[MAXLINE];
	char line_2[MAXLINE]; 
	int n_cntr_1 = 0;
	int n_cntr_2 = 0; 
	char ch; 

	printf("Enter first line: ");
	for (int i = 0; i < MAXLINE - 1 && (ch = getchar()) != EOF && ch != '\n'; i++, n_cntr_1++)
		line_1[i] = ch;
	line_1[n_cntr_1] = '\0';

	printf("Enter second line: ");
	for (int i = 0; i < MAXLINE - 1 && (ch = getchar()) != EOF && ch != '\n'; i++, n_cntr_2++)
		line_2[i] = ch;
	line_2[n_cntr_2] = '\0';

	printf("Before the transformation:\n");
	printf("%s\n", line_1);
	printf("%s\n", line_2);

	squeeze(line_1, line_2);
	printf("After the transformation:\n");
	printf("%s\n", line_1);
	printf("%s\n", line_2);
}

void squeeze(char st_1[], char st_2[])
{
	int i = 0, j = 0;
	int m, n;

	while (st_2[i] != '\0')
	{
		if (st_1[j] == st_2[i])
		{
			for (m = n = j; st_1[n] != '\0'; m++)
				st_1[m] = st_1[++n];
		}
		else if (st_1[j] == '\0')
		{
			i++;
			j = 0;
		}
		else j++;
	}
}