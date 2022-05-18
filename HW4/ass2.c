/* 
assignment :4
campus : beer sheva,israel
auther: ahmad abo mdegam
id:209101948
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void bulidmatrix(int ***, int, int);
void insert(int ***, int, int);//founction helping
void PrintMatrix(int **, int, int);
void GetMinMax(int **, int, int, int *, int *);
void insertRow(int *, int *);//founction helping
void bulidRow(int **, int *);
void AddRow(int ***, int *, int, int *, int);
void bulidmatrix1(int ***, int, int); //founction helping
void RemoveColumn(int ***, int, int *, int);
void bulidmatrix2(int ***, int, int); //founction helping
void FreeMatrix(int ***, int);
int main()
{
    int **matrix, col, row,i;
    int max, min, *prow, cols = 0, *newrow = NULL, coln;
    printf("Enter count of row & columns:\n");
    scanf("%d%d", &col, &row);
    bulidmatrix(&matrix, row, col);

    PrintMatrix(matrix, row, col);
    bulidRow(&newrow, &cols);
    AddRow(&matrix, &row, col, newrow, cols);
    PrintMatrix(matrix, row, col);
    printf("Enter the col you want to remove:\n");
    scanf("%d", &coln);
    RemoveColumn(&matrix, row, &col, coln);
    PrintMatrix(matrix, row, col);
    GetMinMax(matrix, row, col, &min, &max);
   
    printf("the max %d & min %d.\n", max, min);
    FreeMatrix(&matrix,row);
    return 0;
}

void bulidmatrix(int ***matrix, int row, int col) // bulid the matrix and fill up .
{
    int i, j, k;

    *matrix = (int **)malloc(sizeof(int *) * row);
if(*matrix==NULL)
{
printf("no memmory !!\n");
 exit (1);
}
    for (i = 0; i < row; i++)
        (*matrix)[i] = (int *)malloc(sizeof(int) * col);

    insert(matrix, row, col);
}

void insert(int ***matrix, int row, int col) // fill up the matrix numbers
{
    int i, k;
    for (i = 0; i < row; i++)
        for (k = 0; k < col; k++)
        {
            printf("Enter [%d][%d] element:\n", i, k);
            scanf("%d", &(*matrix)[i][k]);
        }
}

void PrintMatrix(int **matrix, int row, int col) // print the matrix by count of column and rows
{
    int i, k;
    for (i = 0; i < row; i++)
    {
        for (k = 0; k < col; k++)
            printf("%d ", matrix[i][k]);
        printf("\n");
    }
}

void GetMinMax(int **matrix, int row, int col, int *pmin, int *pmax) // checking the max and min digit and change it by pointor to printing in main.
{
    int i, max = matrix[0][0];
    int k, min = matrix[0][0];
    *pmax = max;
    *pmin = min;
    for (i = 0; i < row; i++)
    {
        for (k = 0; k < col; k++)
        {
            if (*pmax < matrix[i][k])
                *pmax = matrix[i][k];
            if (*pmin > matrix[i][k])
                *pmin = matrix[i][k];
        }
    }
}

void bulidRow(int **Row, int *psize) // bulid new row to add it in the matrix
{
    int num;

    printf("Please Enter count of the columns:\n");
    scanf("%d", &num);
    *psize = num;
    *Row = (int *)malloc(num * sizeof(int));
    if (*Row == NULL)
    {
        printf("No memory !!\n");
        exit(1);
    }
    insertRow(*Row, psize);
}

void insertRow(int *pc, int *size) // fill up the row numbers
{
    for (int i = 0; i < *size; i++)
    {
        printf("Enter the element [%d]:\n ", i);
        scanf("%d", &pc[i]);
    }
}

void AddRow(int ***matrix, int *prow, int col, int *newrow, int columns) //the founction add new row by new help matrix. 
{
    int i, k, j;
    int **newmatrix;

   if (col == columns)
    
    {
       
     
    bulidmatrix1(&newmatrix, *prow, col);
    if (newmatrix == NULL)
    {
        printf("No memmory !!\n");
        exit(1);
    }

    for (i = 0; i < *prow; i++)
        for (k = 0; k < col; k++)
            newmatrix[i][k] = (*matrix)[i][k];
    for (j = 0; j < columns; j++)
        newmatrix[*prow][j] = newrow[j];
    *matrix = newmatrix;

    *prow += 1;
}
else
 printf("inccorict count of columns!!\n");
}
void bulidmatrix1(int ***matrix1, int row, int col)
{
    int i, j, k;

    *matrix1 = (int **)malloc(sizeof(int *) * row);
if(*matrix1==NULL)
{
printf("no memmory !!\n");
 exit (1);
}
    for (i = 0; i < row + 1; i++)
        (*matrix1)[i] = (int *)malloc(sizeof(int) * col);
}

void RemoveColumn(int ***matrix, int row, int *pcol, int coln) // the user enter number of column what who want to remove and the founction remove the col.
{
    int **matrixcol, k, i;
    while (coln >= *pcol||coln<0 )

    {
        printf("incorect column number!!\n");
        printf("Try again:\n");
        scanf("%d", &coln);
    }

    bulidmatrix2(&matrixcol, row, *pcol); 
    for (i = 0; i < row; i++)
        for (k = 0; k < *pcol; k++)
        {
            if (k == coln)
            {
                matrixcol[i][k] = (*matrix)[i][k + 1];
                k++;
            }
            else
                matrixcol[i][k] = (*matrix)[i][k];
        }
    *matrix = matrixcol;
    *pcol -= 1;
}

void bulidmatrix2(int ***matrix2, int row, int col) // founction to bulid matrix new count columns. 
{
    int i, j, k;

    *matrix2 = (int **)malloc(sizeof(int *) * row);
if(*matrix2==NULL)
{
printf("no memmory !!\n");
 exit (1);
}
    for (i = 0; i < row ; i++)
{
        (*matrix2)[i] = (int *)malloc(sizeof(int) * col - 1);
if((*matrix2)[i]==NULL)
{
printf("no memmory !!\n");
 exit (1);
}
}
void FreeMatrix(int ***matrix, int row) // free matrix after use it.
{
    int i;
    for (i = 0; i < row; i++)
        free((*matrix)[i]);
        free(*matrix);

    
}
