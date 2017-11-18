#include <stdio.h>
#include "malloc.h"

#define BUF 50
int incSize = 0;

void incListInput(int**, int);
void incListOutput(int**, int);
void incList_to_adjMat(int**, int**, int);
void adjMatOutput(int**, int);

main()
{
    int tops;
    printf("\tINCIDENCE LIST INPUT\n");
    printf("Enter number of tops\ntops = ");
    scanf("%d", &tops);
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

    int **adjMat = (int **)malloc(tops*sizeof(int *));
    for (int i = 0; i < tops; i++) {
        adjMat[i] = (int *)malloc(tops*sizeof(int));
    }

    incList_to_adjMat(incList, adjMat, tops);

    printf("\n\tYOUR ADJACENCY MATRIX\n");
    adjMatOutput(adjMat, tops);
    printf ('\n');

    for (int i = 0; i < tops; i++) {
        free(adjMat[i]);
    }
    free(adjMat);
    for (int i = 0; i < tops; i++) {
        free(incList[i]);
    }
    free(incList);
}

void incList_to_adjMat(int **incList, int **adjMat, int tops)
{
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; incList[i][j] != 0; j++)
        {
            adjMat[i][incList[i][j] - 1] = 1;
            adjMat[incList[i][j] - 1][i] = 1;
        }
    }
}

void adjMatOutput(int **adjMat, int tops)
{
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
        {
            printf ("%d ", adjMat[i][j]);
        }
        printf ("\n");
    }
}

void incListInput(int **incList, int tops)
{
    int count;
    int num;

    for (int i = 0; i < tops; i++)
    {
        printf("Enter the number of vertices adjacent to the %d vertex: ", i + 1);
        scanf("%d", &num);
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
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &incList[i][j]);
            count++;
        }
        if (count > incSize)
            incSize = count;
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
