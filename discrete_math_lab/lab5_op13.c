#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

void adjMat_input(int**, int);
void Mat_output(int**, int, int);

void adjMat_to_incMat(int**, int**, int, int);

main()
{
	int tops;
	printf("Enter number of tops = ");
	scanf_s("%d", &tops);

	int **adjMat = (int **)malloc(tops*sizeof(int *));
	for (int i = 0; i < tops; i++) {
		adjMat[i] = (int *)malloc(tops*sizeof(int));
	}

	printf("\tADJMAT INPUT\n");
	adjMat_input(adjMat, tops);
	printf("\n\tADJMAT OUTPUT\n");
	Mat_output(adjMat, tops, tops);
	printf("\n");

	int ribs = 0;
	for (int i = 0; i < tops; i++)
	for (int j = 0; j < tops; j++)
	if (adjMat[i][j] != 0)
		ribs += adjMat[i][j];

	int **incMat = (int **)malloc(tops*sizeof(int *));
	for (int i = 0; i < tops; i++) {
		incMat[i] = (int *)malloc(ribs*sizeof(int));
	}
	for (int i = 0; i < tops; i++)
	for (int j = 0; j < ribs; j++)
		incMat[i][j] = 0;

	adjMat_to_incMat(adjMat, incMat, tops, ribs);
	printf("\n\tINCMAT OUTPUT\n");
	Mat_output(incMat, tops, ribs);
	printf("\n");



	////////
	for (int i = 0; i < tops; i++) {
		free(adjMat[i]);
	}
	free(adjMat);
	for (int i = 0; i < tops; i++) {
		free(incMat[i]);
	}
	free(incMat);
}

void adjMat_to_incMat(int **adjMat, int **incMat, int tops, int ribs)
{
	int temp = abs(tops - ribs);

	int mid = -1;
	if (tops % 2 != 0)
		mid = tops / 2 + 1;

	for (int i = 0; i < tops; i++)
	{
		for (int j = 0; j < tops; j++)
		{
			if (i == j && adjMat[i][j] == 0)
				continue;

			if (i == mid)
			{
				for (int z = 0; z < tops; z++)
				{
					if (adjMat[i][z] == 1)
						incMat[i][z] = 1;
				}
				continue;
			}

			if (adjMat[i][j] == 1 && j > i)
				incMat[i][j - temp] = 1;
			else if (adjMat[i][j] == 1 && j < i)
				incMat[i][j + temp] = 1;

			if (adjMat[i][j] == 0 && adjMat[j][i] == 1 && j < i)
				incMat[i][j] = -1;
			else if (adjMat[i][j] == 0 && adjMat[j][i] == 1 && j > i)
				incMat[i][j - temp] = -1;

		}
	}
}

void adjMat_input(int **adjMat, int tops)
{
	for (int i = 0; i < tops; i++)
	{
		for (int j = 0; j < tops; j++)
		{
			scanf_s("%d", &adjMat[i][j]);
		}
	}
}

void Mat_output(int **Mat, int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", Mat[i][j]);
		}
		printf("\n");
	}
}