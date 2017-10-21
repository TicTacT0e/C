#include <stdio.h> 
#include <math.h>

#define MAXLINE 1000

int htol(char[], int); 
unsigned int char2int_(char chr);

main()
{
	char h_number[MAXLINE];
	int char_main; 
	int null_count = 0;
	int hexadec; 

	for (int i = 0; i < MAXLINE - 1 && (char_main = getchar()) != EOF && char_main != '\n'; i++, null_count++)
		h_number[i] = char_main; 
	h_number[null_count] = '\0'; 

	hexadec = htol(h_number, null_count);
	printf("%d\n", hexadec);
}

int htol(char h_decimal[], int char_count)
{
	int num = 0; 
	for (int i = 0, j = char_count - 1; i < char_count; i++, j--)
		num += char2int_(h_decimal[i]) * pow(16, j); 
	return num; 
}

unsigned int char2int_(char chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';
	else if (chr >= 'A' && chr <= 'F')
		return chr - 'A' + 10;
	else if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;
	return -1;
}