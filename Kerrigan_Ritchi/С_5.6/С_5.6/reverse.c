#include <stdio.h> 
#include "C_5.6.h"

/*��������� ������*/

void reverse(char *s)
{
	char c;
	char *t;

	for (t = s + (strlen(s) - 1); s < t; s++, t--)
	{
		c = *s;
		*s = *t;
		*t = c;
	}
}



//  �� �������� � �������������� ��������� 

/*void reverse(char *s)
{
	char temp[SIZE]; 
	char *t = temp; 
	char start = *s; //�� �� ����� 

	while (*t = *s)
	{
		t++;
		s++;
	}
	while (*s != start) // � ����� 
		s--;
	t--; 
	while (*s)
	{
		*s = *t; 
		s++;
		t--;
	}
	*s = '\0';
}
*/

