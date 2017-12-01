#include <stdio.h>
#include <malloc.h>

/* Develop an algorithm for converting a list of pairs into an adjacency
 * matrix for oriented graph */

/* Входные параметры - количество ребер
 * список пар в виде матрицы [количество ребер][2] */

void matInput (int**, int, int);
void matOutput (int**, int, int);
void pairList_to_adjMatrix (int **, int, int **);


main() {

    int ribs;
    printf ("Enter number of ribs: ");
    scanf ("%d", &ribs);

    int **pairList = (int **)malloc(ribs*sizeof(int *));
    for (int i = 0; i < ribs; i++){
        pairList[i] = (int *)malloc(2*sizeof(int));
    }

    printf("\tPAIR LIST INPUT\n");
    matInput(pairList, ribs, 2);
    printf("\n\tYOUR PAIR LIST\n");
    matOutput(pairList, ribs, 2);
    printf("\n");

    int tops = pairList[0][0];
    for (int i = 0; i < ribs; i++)
    {
        for (int j = 0; j < 2; j++)
        {
         if (tops < pairList[i][j])
             tops = pairList[i][j];
        }
    }

    int **adjMatrix = (int **)malloc(tops*sizeof(int *));
    for (int i = 0; i < tops; i++){
        adjMatrix[i] = (int *)malloc(tops*sizeof(int));
    }

    pairList_to_adjMatrix(pairList, ribs, adjMatrix);
    printf("\tYOUR ADJACENCY MATRIX\n");
    matOutput(adjMatrix, tops, tops);
}

void pairList_to_adjMatrix(int** pairList, int x, int** adjMatrix)
{
    for (int i = 0; i < x; i++)
    {
        adjMatrix[pairList[i][0] - 1][pairList[i][1] - 1] = 1;
    }
}

void matInput (int** mat, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf ("%d", &mat[i][j]);
        }
    }
}

void matOutput (int** mat, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
