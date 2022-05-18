/* 
assignment :5
campus : beer sheva,israel
auther: ahmad abo mdegam
id:209101948
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define SIZE 5
typedef enum
{
    False,
    True
} Bool;

typedef struct
{
    char *name;
    int number_department;
    float salary;
} Employee;
Bool initEmployee(Employee *);//to fill one
int bulidFactory(Employee **pdate);//to fill out the information of workers
void FreeEmployee(Employee **pdata, int size);//to free the memmory 
void calcAvereges(Employee *data, int size, float *result);//founction to calculate averge of salary by department
void ShowWorkers(Employee *work, int count);//founction helping to print information of workers
int main()
{
    Employee *arr;
    int count;
    float result[SIZE];
    count = bulidFactory(&arr);
    calcAvereges(arr, count, result);
    ShowWorkers(arr, count);
    for (int i = 0; i < SIZE; i++)
        printf("the averge of department number %d is %.2f\n", i + 1, result[i]);
    FreeEmployee(&arr, count);
    return 0;
}
Bool initEmployee(Employee *employee)
{
    char buffer[20];
    printf("Enter name of employee:\n");
    scanf("%s", buffer);
    employee->name = (char *)calloc(strlen(buffer) + 1, sizeof(char));//dynamic allocation name
    if (employee->name == NULL)
    {
        printf("No memmory!!");
        return False;
    }
    strcpy(employee->name, buffer);//copy the word
    do{
    printf("Enter number of debartment 1-5:\n");
    scanf("%d", &employee->number_department);
    }while(employee->number_department<=0||employee->number_department>5);
    printf("Enter salary of employee:\n");
    scanf("%f", &employee->salary);

    return True;
}
//end Bool

void calcAvereges(Employee *data, int size, float *result)// claculate the averge by department
{
    int j, c;
    float sum;
    for (int i = 0; i < SIZE; i++)
    {
        sum = 0;
        c = 0;
        for (j = 0; j < size; j++)
            if ((data + j)->number_department == i + 1)
            {
                c++;//to know count of workers in department 
                sum += (data + j)->salary;
            }
        if (c == 0)
            result[i] = -1;
        else
        {
            result[i] = (float)sum / c;
        }
    }
}
int bulidFactory(Employee **pdate)//too fill out the information of workers
{
    int count;
    printf("Enter Count of workers:\n");
    scanf("%d", &count);
    *pdate = (Employee *)malloc(count * (sizeof(Employee)));
    for (int i = 0; i < count; i++)
    {
        printf("Please enter an information to the employee number %d:\n", i + 1);
        if (initEmployee((*pdate + i)) == True)
            ;
    }
    return count;
}
void ShowWorkers(Employee *work, int count)//to print the information of workers
{
    for (int i = 0; i < count; i++)
        printf("%s: %d, %.2f.\n", (work + i)->name, (work + i)->number_department, (work + i)->salary);
}

void FreeEmployee(Employee **pdata, int size)
{
    for (int i = 0; i < size; i++)//free name
    {
        free((*pdata + i)->name);
        (*pdata + i)->name = NULL;
    }
    free(*pdata);//free all
    *pdata = NULL;
}
