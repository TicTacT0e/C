#include <stdio.h>
#include "head.h"

int main()
{
	int nlines; /* ���������� ����������� ����� */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		writelines(lineptr, nlines);
		return 0; 
	}
	else {
		printf("ouin6Ka: ������� ����� �����\n");
		return 1;
	}
}