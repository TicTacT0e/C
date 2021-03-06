#include "stdio.h"
#include "malloc.h"
#include "ctype.h"
#include "stdlib.h"

/*Develop an algorithm for converting an incidence list
*into a list of pairs for undirected graph.*/

void incListInput(int**, int);
void incListOutput(int**, int);

#define BUF 50
int incSize = 0;

int bufPairList[BUF][2];
int pairList[BUF][2];
int pair_count = 0;
void addPair(int, int);
void pairListOutput();

void incList_to_pairList(int**, int);
void pairListClean();

int integerInput();

main()
{
	for (int i = 0; i < BUF; i++)
	for (int j = 0; j < 2; j++)
	{
		bufPairList[i][j] = 0;
		pairList[i][j] = 0;
	}

	int tops;
	printf("\tINCIDENCE LIST INPUT\n");
	printf("Enter number of tops\ntops = ");

	tops = integerInput();
	printf("%d\n", tops);

	int **incList = (int **)malloc(tops*sizeof(int *));
	for (int i = 0; i < tops; i++) {
		incList[i] = (int *)malloc(BUF*sizeof(int));
	}
	for (int i = 0; i < tops; i++)
	for (int j = 0; j < BUF; j++)
		incList[i][j] = 0;
	incListInput(incList, tops);
	printf("\n\tYOUR INCIDENCE LIST\n");
	incListOutput(incList, tops);

	incList_to_pairList(incList, tops);
	pairListClean();

	printf("\n\tYOUR PAIR LIST\n");
	pairListOutput();

	for (int i = 0; i < tops; i++) {
		free(incList[i]);
	}
	free(incList);
}

int integerInput()
{
	int i, ch; char value[BUF]; int dig; 

	int flag; 

	while (1) {
		flag = 0; 

		for (i = 0; i < BUF - 1 && (ch = getchar()) != '\n'; i++)
		{
			if (ch == EOF)
				return -1; 
			value[i] = ch;
		}
		value[i] = '\0';
		for (int j = 0; j < i; j++)
		{
			if (!isdigit(value[j]))
			{
				printf("Incorre�t input, try again...\n");
				flag = 1; 
				break;
			}
		}
		if (flag == 1)
			continue; 

		dig = 0; 
		for (int j = 0; value[j] >= '0' && value[j] <= '9'; ++j)
			dig = 10 * dig + (value[j] - '0');
		return dig; 
	}
}

void pairListClean()
{
	int flag;
	int a, b;
	int list_ctr = 0;

	for (int i = 0; i < BUF; i++)
	{
		a = bufPairList[i][0]; b = bufPairList[i][1];
		flag = 0;
		for (int k = i + 1; k < BUF; k++)
		{
			if ((a == bufPairList[k][0] && b == bufPairList[k][1]) || (b == bufPairList[k][0] && a == bufPairList[k][1]))
				flag++;
		}
		if (flag == 4 || flag == 2 || flag == 0)
		{
			pairList[list_ctr][0] = bufPairList[i][0];
			pairList[list_ctr][1] = bufPairList[i][1];
			list_ctr++;
		}
	}
}


void incList_to_pairList(int **incList, int tops)
{
	for (int i = 0; i < tops; i++)
	{
		for (int j = 0; j < incSize; j++)
		{
			if (incList[i][j] != 0)
				addPair(i + 1, incList[i][j]);
		}
	}
}

void addPair(int a, int b)
{
	bufPairList[pair_count][0] = a;
	bufPairList[pair_count][1] = b;
	pair_count++;
}

void pairListOutput()
{
	int flag = 1;

	for (int i = 0; i < BUF; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (pairList[i][0] == 0 || pairList[i][1] == 0)
			{
				flag = 0;
				break;
			}
			printf("%d ", pairList[i][j]);
		}
		printf("\n");
		if (flag == 0)
			break;
	}
}

void incListInput(int **incList, int tops)
{
	int count;
	int i, j; 

	for (i = 0; i < tops; i++)
	{
		printf("Press \"Enter\" to enter value...\nTo stop entering values, press CTRL+Z\n"); 
		count = 0;
		printf("Incidence list for the %d", i + 1);
		if ((i + 1) == 1)
			printf("st ");
		else if ((i + 1) == 2)
			printf("nd ");
		else if ((i + 1) == 3)
			printf("rd ");
		else printf("th ");
		printf("vertex: ");
		for (j = 0; (incList[i][j] = integerInput()) != EOF; j++)
			count++;
		if (count > incSize)
			incSize = count;
		incList[i][j] = 0; 
	}
	printf("\n");
}


void incListOutput(int **incList, int tops)
{
	for (int i = 0; i < tops; i++)
	{
		printf("%d", i + 1);
		if ((i + 1) == 1)
			printf("st ");
		else if ((i + 1) == 2)
			printf("nd ");
		else if ((i + 1) == 3)
			printf("rd ");
		else printf("th ");
		printf("vertex: ");
		for (int j = 0; j < incSize; j++)
		{
			printf("%d ", incList[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}