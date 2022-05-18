/* 
assignment :5
campus : beer sheva,israel
auther: ahmad abo mdegam
id:209101948
*/

#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    False,
    True
} Bool;
int Mindigit(int);
Bool Boolarr(int[], int);
int Sumevindigit(int[], int size);
int strcmp(char *, char *);
void Convert(int *, int);
int ToBinary(int);
int LenOfStr(char *str);
int Maxlenword(char **, int, int *);
int main()
{
    int num, binary, size, *ar, count = 4;
    int how = 0;
    char word, *string[] = {"ahmad", "slamh", "slem", "slman"};
    printf("Please Enter number:\n");
    scanf("%d", &num);
    printf("The min digit in number is :%d\n", Mindigit(num));
    printf("Please Enter number to convert it to binary:\n");
    scanf("%d", &binary);
    printf("The number in binary :%d\n", ToBinary(binary));
    printf("Please Enter size of array:\n");
    scanf("%d", &size);
    ar = (int *)malloc(size * sizeof(int));
    if (ar == NULL)
    {
        printf("No memmory!!\n");
        return 0;
    }
    for (int i = 0; i < size; i++)
    {
        printf("Please Enter element :\n");
        scanf("%d", &ar[i]);
    }
    //check the array odd or not
    if (Boolarr(ar, size))
        printf("True\n");
    else
        printf("False\n");
        //sum all even digit
    printf("sum of all even digits is :%d\n", Sumevindigit(ar, size));
    // convert and change the array
    Convert(ar, size);
    printf("the new array is : {");
    for (int i = 0; i < size - 1; i++)
        printf("%d,", ar[i]);
    printf("%d}", ar[size - 1]);
    printf("\n");
    // strlen
    printf("the long of word is: %d\n", LenOfStr("ahmad"));
    //compare between two words
    if (strcmp("ahmad", "Ahmad") == 0)
        printf("equal word\n");
    else if (strcmp("ahmad", "Ahmad") > 0)
        printf("the first word is big!!\n");
    else
        printf("the sucend word is big!!\n");
    //the long words in string 
    printf("the long of longest words is:%d and how much is %d.\n", Maxlenword(string, count, &how), how);
}
//end main
int Mindigit(int num)
{
    int rest;
    if (num / 10 == 0) // stop conditions
        return num;
    else
    {
        rest = Mindigit(num / 10);
        if (rest > num % 10) //cheking the min digit and returned it.
            return num % 10;
        else
            return rest;
    }
}
//end mindigit
int ToBinary(int num)
{
    int x = 0, i = 1;
    if (num == 0) // stop conditions

        return 0;

    else
    {
        return (num % 2) + 10 * ToBinary(num / 2);
    }
}
//end binary
Bool Boolarr(int arr[], int size)
{
    if (size == 1) // stop conditions
    {
        if (arr[0] % 2 == 0)
            return False;
        else
            return True;
    }
    else if (arr[size - 1] % 2 == 1)
        return Boolarr(arr, size - 1);
    else
        return False;
}
//end Boolarr
int Sumevindigit(int arr[], int size)
{
    if (size == 1) // stop conditions
    {
        if (arr[size - 1] % 2 == 0)
            return arr[size - 1];
        else
            return 0;
    }
    else
    {
        if (arr[size - 1] % 2 == 0)
            return arr[size - 1] + Sumevindigit(arr, size - 1);
        else
            return Sumevindigit(arr, size - 1);
    }
}
//end sumevindigit
void Convert(int *arr, int size)
{
    if (size == 1) // stop conditions
        return;
    else
    {
        arr[1] += arr[0];
        Convert(arr + 1, size - 1);
    }
}
//end convert
int LenOfStr(char *str)
{
    if (*str == '\0')// stop conditions
        return 0;
    else
        return 1 + LenOfStr(str + 1);
}
//end lenofstr
int strcmp(char *word1, char *word2)
{
    if (word1[0] == '\0' && word2[0] == '\0') // stop conditions
        return 0;
    else
    {
        if (word1[0] == word2[0])
        {
            return strcmp(word1 + 1, word2 + 1);
        }
        else
            return (word1[0] - word2[0]) + strcmp(word1 + 1, word2 + 1);
    }
}
//end copmare
int Maxlenword(char **string, int count, int *how)
{
    int c = 0, max;
    if (count == 1)// stop conditions
        return LenOfStr(string[0]);
    else
    {

        max = Maxlenword(string + 1, count - 1, how);
        if (LenOfStr(string[0]) > max)
            return LenOfStr(string[0]);
        else
        {
            if (LenOfStr(string[0]) == max)
            {
                c++;
                *how = c;
                return max;
            }
            else
                return max;
        }
    }
}
