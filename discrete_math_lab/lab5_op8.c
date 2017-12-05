#include <stdio.h>
#include "malloc.h"


/*Develop an algorithm for transforming the incidence matrix into a list
 * of pairs for undirected graph*/

/* Входные параметры - количество вершин, кол-во ребер, 0/1 матрица смежности */

void matInput(int **, int, int);

void matOutput(int **, int, int);

void incMatrix_to_pairList(int **, int, int, int **);

void pairListClean(int **, int **, int);


main() {
    int tops, ribs;

    printf("Enter number (integer digit) of tops: ");
    scanf("%d", &tops);
    printf("Enter number (integer digit) of ribs: ");
    scanf("%d", &ribs);
    int **incMatrix = (int **) malloc(tops * sizeof(int *));
    for (int i = 0; i < tops; i++) {
        incMatrix[i] = (int *) malloc(ribs * sizeof(int));
    }
    for (int i = 0; i < tops; i++) {
        for (int j = 0; j < ribs; j++) {
            incMatrix[i][j] = 0;
        }
    }

    printf("\tINCIDENCE MATRIX INPUT\n");
    matInput(incMatrix, tops, ribs);
    printf("\n\tYOUR INCIDENCE MATRIX\n");
    matOutput(incMatrix, tops, ribs);
    printf("\n");

    int bufList = 0;

    for (int i = 0; i < tops; i++) {
        for (int j = 0; j < ribs; j++) {
            if (incMatrix[i][j] == 1)
                bufList++;
        }
    }

    int **bufPairList = (int **) malloc(bufList * sizeof(int *));
    for (int i = 0; i < bufList; i++) {
        bufPairList[i] = (int *) malloc(2 * sizeof(int));
    }

    int **pairList = (int **) malloc(ribs * sizeof(int *));
    for (int i = 0; i < ribs; i++) {
        pairList[i] = (int *) malloc(2 * sizeof(int));
    }

    incMatrix_to_pairList(incMatrix, tops, ribs, bufPairList);

    for (int i = 0; i < bufList; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", bufPairList[i][j]);
        }
        printf("\n");
    }

    pairListClean(pairList, bufPairList, bufList);
    printf("\n\tYOUR INCIDENCE MATRIX\n");
    matOutput(pairList, ribs, 2);


    for (int i = 0; i < tops; i++) {
        free(incMatrix[i]);
    }
    free(incMatrix);
    for (int i = 0; i < bufList; i++) {
        free(bufPairList[i]);
    }
    free(bufPairList);
    for (int i = 0; i < ribs; i++) {
        free(pairList[i]);
    }
    free(pairList);

}

void incMatrix_to_pairList(int **incMatrix, int tops, int ribs, int **bufPairList) {

    int z = 0;

    int midColums;
    if (ribs % 2 != 0) {
        midColums = ribs / 2;
    } else midColums = ribs / 2;

    printf("midColums - %d\n\n", midColums);

    if (tops == ribs) {
        for (int i = 0; i < tops; i++) {
            for (int j = 0; j < ribs; j++) {
                if (incMatrix[i][j] == 1 && j < midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                } else if (incMatrix[i][j] == 1 && j > midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 1;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 != 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 3;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 == 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                }
            }
        }
    } else if (tops > ribs) {
        int midRows;
        if (tops % 2 != 0) {
            midRows = tops / 2;
        } else midRows = tops / 2;

        printf("midRows - %d\n\n", midRows);

        for (int i = 0; i < midRows; i++) {
            for (int j = 0; j < ribs; j++) {
                if (incMatrix[i][j] == 1 && j < midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                } else if (incMatrix[i][j] == 1 && j > midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 1;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 != 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 3;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 == 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                }
            }
        }
    } else if (tops < ribs) {
        int midRows;
        if (tops % 2 != 0) {
            midRows = tops / 2;
        } else midRows = tops / 2;

        int temp = ribs - tops;

        printf("midRows - %d\n\n", midRows);

        for (int i = 0; i < midRows; i++) {
            for (int j = 0; j < ribs; j++) {
                if (incMatrix[i][j] == 1 && j < midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                } else if (incMatrix[i][j] == 1 && j > midColums) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 1;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 != 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 3;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == midColums && ribs % 2 == 0) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 2;
                    z++;
                } else if (incMatrix[i][j] == 1 && j == ribs - 1) {
                    bufPairList[z][0] = i + 1;
                    bufPairList[z][1] = j + 1 - temp;
                    z++;
                }
            }
        }
    }
}

void pairListClean(int **pairList, int **bufPairList, int bufList) {
    int list_ctr = 0;

    for (int i = 0; i < bufList; i++) {
        if ((bufPairList[i][0] != bufPairList[i][1]) && (bufPairList[i][0] != 0 || bufPairList[i][1] != 0)) {
            pairList[list_ctr][0] = bufPairList[i][0];
            pairList[list_ctr][1] = bufPairList[i][1];
            list_ctr++;
        }
    }
}

void matInput(int **mat, int x, int y) {
    printf("Enter only 0 or 1\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void matOutput(int **mat, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if ((mat[i][j] == 0) && (mat[i][j+1] == 0))
                break;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}