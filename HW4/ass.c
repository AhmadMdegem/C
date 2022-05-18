/* 
assignment :4
campus : beer sheva,israel
auther: ahmad abo mdegam
id:209101948
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void bulidgruop(int **, int *);
int checker(int *, int *);
void insert(int *, int *);
void printgruop(int **, int);
int *Union(int *, int, int *, int, int *);
int similar(int *, int, int *, int);
int *intersection(int *, int, int *, int, int *);
int *Diff(int *, int, int *, int, int *);

int main()
{
    int *gruop1, *gruop2, size1, size2, diffsize = 0;
    int *aehod, *hetoh, *diff, nusize = 0, hsize = 0;
    printf("Enter the first gruop:\n");
    bulidgruop(&gruop1, &size1);
    printf("Enter the sucend gruop:\n");
    bulidgruop(&gruop2, &size2);
    printf("The first gruop is:  ");
    printgruop(&gruop1, size1);
    printf("The sucend gruop is:  ");
    printgruop(&gruop2, size2);
    aehod = Union(gruop1, size1, gruop2, size2, &nusize);
    printf("The consolidatio of the gruops is:  ");
    printgruop(&aehod, nusize);
    hetoh = intersection(gruop1, size1, gruop2, size2, &hsize);
    printf("The cut of the gruops is:  ");
    printgruop(&hetoh, hsize);
    diff = Diff(gruop1, size1, gruop2, size2, &diffsize);
    printf("The difference of the gruops is:  ");
    printgruop(&diff, diffsize);
    free(gruop1);
    free(gruop2);
    return 0;
}
void bulidgruop(int **gruop, int *psize)
{
    int num;

    printf("Please Enter count of the gruop:\n");
    scanf("%d", &num);
    *psize = num;
    *gruop = malloc((*psize) * sizeof(int));
    if (*gruop == NULL)
    {
        printf("No memory !!\n");
        exit(1);
    }
    insert(*gruop, psize); // recive numbers to gruop;
}
void insert(int *pc, int *size)
{
    int x;
    for (int i = 0; i < *size; i++)
    {
        do
        {
            printf("Enter the %d element:\n", i);
            scanf("%d", pc + i);
            x = checker(pc, &i); // check if the number available or no in gruop;
        } while (x == 0);
    }
}
int checker(int *gr, int *size)
{

    for (int i = 0; i < *size; i++)
        for (int k = 1 + i; k <= *size; k++)
            if (*(gr + i) == *(gr + k))
                return 0;

    return 1;
}
void printgruop(int **gr, int size) //print the gruop
{
    int i, cn = size - 1;
    if (size == 0)
        printf("{}");
    if (size != 0)
    {
        printf("{");
        for (i = 0; i < cn; i++)
            printf("%d,", *(*gr + i));
        printf("%d", *(*gr + cn));
        printf("}");
    }
    printf("\n");
}
int *Union(int *grup1, int size1, int *grup2, int size2, int *psizeunion)
{
    int i, j, k = 0, cn = 0, *grunion;
    int flag = 0;
    cn = (size1 + size2) - similar(grup1, size1, grup2, size2);  // count what i need to memmory;(no english)
    grunion = (int *)malloc(cn * sizeof(int));
    if (grunion == NULL)
    {
        printf("no memmory\n");
        exit(1);
    }
    for (i = 0; i < size1; i++)
        *(grunion + i) = *(grup1 + i);
    for (i = 0; i < size2; i++)
    {
        flag = 0;
        for (j = 0; j < size1 && flag == 0; j++)
        {
            if (*(grup2 + i) != *(grunion + j))

                flag = 0;
            else
                flag = 1;
        }
        if (flag == 0)
        {
            *(grunion + size1 + k) = *(grup2 + i);
            k++;
        }
    }
    *psizeunion = cn;
    return grunion;
}
int similar(int *gr1, int size1, int *gr2, int size2)//checking if find the number between two gruop
{
    int i, flag = 0, j, cn = 0;
    for (i = 0; i < size2; i++)
    {
        flag = 0;
        for (j = 0; j < size1 && flag == 0; j++)
            if (*(gr2 + i) == *(gr1 + j))
            {
                cn++;
                flag = 1;
            }
    }
    return cn;
}

int *intersection(int *grp1, int size1, int *grp2, int size2, int *psizeinter) //new gruop containt all numbers apper in two gruops
{
    int i, j = 0, k, cn = 0, *grinter = NULL;
    int flag = 0;
    cn = similar(grp1, size1, grp2, size2);
    grinter = (int *)malloc(cn * sizeof(int));
    if (grinter == NULL)
    {
        printf("No memmory!!\n");
        exit(1);
    }
    for (k = 0; k < size1; k++)
        for (i = 0; i < size2; i++)
            if (*(grp2 + i) == *(grp1 + k))
            {
                *(grinter + j) = *(grp2 + i);
                j++;
            }

    *psizeinter = cn;
    return grinter;
}
int *Diff(int *group1, int size1, int *group2, int size2, int *psizeDiff) // new gruop remove the number in first gruop if it apper in the sucend gruop
{
    int cn = 0, k = 0, i, flag = 0, j;
    int *grdiff = NULL;
    cn = size1 - similar(group1, size1, group2, size2);
    grdiff = (int *)malloc(cn * sizeof(int));
    if (grdiff == NULL)
    {
        printf("No memmory !!\n");
        exit(1);
    }
    for (i = 0; i < size1; i++)
    {
        flag = 0;
        for (j = 0; j < size2 && flag == 0; j++)
        {
            if (*(group1 + i) != *(group2 + j))

                flag = 0;
            else
                flag = 1;
        }
        if (flag == 0)
        {
            *(grdiff + k) = *(group1 + i);
            k++;
        }
    }
    *psizeDiff = cn;
    return grdiff;
}
