#include <stdio.h>

#define MAXLINE 1000 

int getline(char[], int);
void reverse(char[], int);

main()
{
	int length; 
	char line[MAXLINE];

	while ((length = getline(line, MAXLINE)) > 0)
	{
		reverse(line, length); 
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

void reverse(char string[], int size)
{
	char temp_string[MAXLINE];
	int null_count = 0;
	for (int i = size - 1, j = 0; j < size; i--, j++, null_count++)
	{
		temp_string[j] = string[i];
	}
	temp_string[null_count] = '\0';
	printf("%s\n", temp_string);
}