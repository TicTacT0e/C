#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAXLINE 1000

int getline(char *line, int max);
/* find: ������ ����� � ��������, �������� 1-� ���������� */
main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus"); 
	printf("%d\n", argc);
	char line[MAXLINE];
		int found = 0;
	if (argc != 2)
		printf("����������� � find �������\n");
	else
	while (getline(line, MAXLINE) > 0) 
	if (strstr(line, argv[1]) != NULL) {
		printf("%s", line);
		found++;
	}
	return found;
}

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

