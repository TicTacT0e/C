#include "stdio.h" //подключение заголовочного файла содержащего библиотеки потоков ввода/вывода
#include "malloc.h" //заголовочный файл для исп. ф-ций выделения/удаления динамической памяти

void adjMat_input(int**, int);  //объявление функции ввода матрицы смежности
void Mat_output(int**, int, int); //объявление функции выводы матриц

void adjMat_to_incMat(int**, int**, int, int); /*объявление функции, содержащей алгоритм преобразования
                                                *матрицы смежности в матрицу инцидентности для
                                                *ориентированного графа*/

main() //главная функция main
{
    //------//инициализация переменной содержащей количество вершин//------//
    int tops;
    printf("Enter number of tops (only integer digit) = ");
    scanf("%d", &tops);
    //------//

    //------//выделение памяти в куче для матрицы смежности//------//
    int **adjMat = (int **)malloc(tops*sizeof(int *));
    for (int i = 0; i < tops; i++) {
        adjMat[i] = (int *)malloc(tops*sizeof(int));
    }
    //------//

    //------//использования функции ввода матрицы смежности для ввода матрицы смежности//------//
    printf("\tADJMAT INPUT\n");
    adjMat_input(adjMat, tops);
    //------//вывод введенной матрицы смежности на экран//------//
    printf("\n\tADJMAT OUTPUT\n");
    Mat_output(adjMat, tops, tops);
    printf("\n");
    //------//

    //------//подсчет количества ребер//------//
    int ribs = 0;
    for (int i = 0; i < tops; i++)
        for (int j = 0; j < tops; j++)
            if (adjMat[i][j] != 0)
                ribs += adjMat[i][j];
    //------//

    //------//выделение памяти в куче для матрицы инцидентности и ее инициализация//------//
    int **incMat = (int **)malloc(tops*sizeof(int *));
    for (int i = 0; i < tops; i++) {
        incMat[i] = (int *)malloc(ribs*sizeof(int));
    }
    for (int i = 0; i < tops; i++)
        for (int j = 0; j < ribs; j++)
            incMat[i][j] = 0;
    //------//

    //------//использование функции преобразования м-и смежности в м-у инцидентности
    //------//функция принимает 4 параметра: указатели на матрицу смежности и инцидентности; переданные по значению
    //------//аргументы количества вершин и ребер//------//
    adjMat_to_incMat(adjMat, incMat, tops, ribs);
    //------//

    //------//ввывод полученной матрицы инцидентности с помощью функции вывода матрицы//------//
    printf("\n\tINCMAT OUTPUT\n");
    Mat_output(incMat, tops, ribs);
    printf("\n");
    //------//

    //------//освобождение динамической памяти//------//
    for (int i = 0; i < tops; i++) {
        free(adjMat[i]);
    }
    free(adjMat);
    for (int i = 0; i < tops; i++) {
        free(incMat[i]);
    }
    free(incMat);
    //------//
}

//------//определение функции преобразования матрицы смежности в матрицу инцидентности//------//
void adjMat_to_incMat(int **adjMat, int **incMat, int tops, int ribs)
{
    int temp = ribs - tops;

    int mid;
    int par = 0;
    if (tops % 2 != 0) {
        mid = tops / 2 + 1;
        par = 1;
    }
    else mid = tops / 2 - 1;

    for (int i = 0; i < tops; i++)
    {
        for (int j = 0, k = 0; j < tops; j++, k++)
        {
            if (i == j && adjMat[i][j] == 0)
                continue;
            else if (i == j && adjMat[i][j] == 1)
            {
                incMat[i][k] = 1;
                k++;
                continue;
            }

            if (adjMat[i][j] == 1 && adjMat[j][i] == 1 && i < j)
            {
                incMat[i][k - 1] = 1;
                incMat[i][k] = -1;
                k++;
                continue;
            }
            else if (adjMat[i][j] == 1 && adjMat[j][i] == 1 && i > j)
            {
                incMat[i][k] = -1;
                incMat[i][k + 1] = 1;
                k++;
                continue;
            }

            if (adjMat[i][j] == 1 && j > i) {
                if (mid < i + par)
                    incMat[i][ribs - (k + 1)] = 1;
                else incMat[i][k - 1] = 1;
            }
            else if (adjMat[i][j] == 1 && j < i) {
                if (mid < i + par)
                    incMat[i][ribs - (k + 1)] = 1;
                else incMat[i][k + temp] = 1;
            }

            if (adjMat[i][j] == 0 && adjMat[j][i] == 1 && j < i) {
                if (mid < i + par)
                    incMat[i][ribs - (k + 1)] = -1;
                else incMat[i][k] = -1;
            }
            else if (adjMat[i][j] == 0 && adjMat[j][i] == 1 && j > i) {
                if (mid < i + par)
                    incMat[i][ribs - (k + 1)] = -1;
                else incMat[i][k + temp] = -1;
            }

        }
    }
}
//------//

//------//ввод матрицы смежности
void adjMat_input(int **adjMat, int tops)
{
    printf("Enter only(!!!!) 0 or 1\n");
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
        {
            scanf("%d", &adjMat[i][j]);
        }
    }
}

//------//вывод матрицы
void Mat_output(int **Mat, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%2d ", Mat[i][j]);
        }
        printf("\n");
    }
}