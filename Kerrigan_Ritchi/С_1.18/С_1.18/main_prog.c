#include <stdio.h> 

#define MAXLINE 1000

int getline(char[], int);

main()
{
	int length; 
	char line[MAXLINE]; 
	int char_main; 

	while ((length = getline(line, MAXLINE)) > 0)
	{
		printf("%d\n", length);
		for (int i = 0; i < length; i++)
		{
			if (line[i] == ' ' && line[i + 1] == ' ')
			{
				for (int j = i; j < length; j++)
				{
					line[j] = line[j + 1];
					if (j == length - 1)
						line[j] = '\0';
				}
				length--;
				i = 0;
			}
		}

		printf("%s\n", line);
	}
}

int getline(char string[], int size)
{
	int char_foo, i;

	for (i = 0; i < size - 1 && (char_foo = getchar()) != EOF && char_foo != '\n'; i++)
		string[i] = char_foo; 
	string[i] = '\0';
	return i; 
}