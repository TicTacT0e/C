#include <stdio.h>
#include "head.h"

int main()
{
	int nlines; /* количество прочитанных строк */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		writelines(lineptr, nlines);
		return 0; 
	}
	else {
		printf("ouin6Ka: слишком много строк\n");
		return 1;
	}
}