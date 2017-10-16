#include <stdio.h>
#include <time.h>

#define MAXLINES 5000

char *lineptr[MAXLINES]; /* указатели на строки */
int readlines(char *[], int);
void writelines(char *[], int);
void qsort(char *[], int, int);

int main()
{
	double start, end;
	start = clock();
	int nlines; /* количество прочитанных строк */
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		end = clock();
		printf("Time: %.3lf\n", (end - start) / CLOCKS_PER_SEC);
		return 0;
	}
	else {
		printf("ouin6Ka: слишком много строк\n");
		return 1;
	}
}

#define MAXLEN 100

int getline(char *, int);
char *alloc(int);

/* readlines: чтение строк */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p;
	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0'; /* убираем символ \n */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* getline: читает строку в s, возвращает длину */
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* writelines: печать строк */
void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* qsort: сортирует v[left]...v[right] по возрастанию */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right) /* ничего не делается, если в массиве */
		return; /* менее двух элементов */
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
	if (strcmp(v[i], v[left]) < 0)
		swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/* swap: поменять местами v[i] и v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; /* память для alloc */
static char *allocp = allocbuf; /* указатель на своб. место */

char *alloc(int n) /* возвращает указатель на п символов */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n; /* пространство есть */
		return allocp - n; /* старое р */
	}
	else /* пространства нет */
		return 0;
}

void afree(char *p) /* освобождает память, на которую указывает р */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}