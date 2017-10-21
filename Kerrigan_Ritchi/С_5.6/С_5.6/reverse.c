#include <stdio.h> 
#include "C_5.6.h"

/*ÏÅĞÅÂÎĞÎÒ ÑÒĞÎÊÈ*/

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



//  ÍÅ ĞÀÁÎÒÀÅÒ Ñ ÏÎÂÒÎĞßŞÙÈÌÈÑß ÑÈÌÂÎËÀÌÈ 

/*void reverse(char *s)
{
	char temp[SIZE]; 
	char *t = temp; 
	char start = *s; //ÈÇ ÇÀ İÒÎÃÎ 

	while (*t = *s)
	{
		t++;
		s++;
	}
	while (*s != start) // È İÒÎÃÎ 
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

