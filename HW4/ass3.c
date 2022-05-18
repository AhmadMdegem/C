#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define diff 32
void BulidStr(char ***, int *);
void frequency(char **, int);
void BulidStrStop(char ***, int *);
int CheckNum(char *word); //founction helping
void smallleter(char ***text, int countword);//founction helping
void prepocessing(char ***text, int *countword, char **stopwords, int countstopwords);

int main()
{
    int count, i, counts;
    char **text, **wordstop;
    BulidStr(&text, &count);
    smallleter(&text, count);
    BulidStrStop(&wordstop, &counts);
    prepocessing(&text, &count, wordstop, counts);
    frequency(text, count);
    return 0;
}
void frequency(char **words, int countword) // count the word how much and printing thw word and how much it in thw string
{
    int c, i, k, x, l, flag;
    for (i = 0; i < countword; i++)
    {
        c = 0;
        for (k = 0; k < countword; k++)
        {

            x = strcmp(words[i], words[k]);
            if (x == 0)
                c++;
        }
        flag = 0;
        for (l = 0; l < i && flag == 0; l++)
        {
            x = strcmp(words[i], words[l]);
            if (x == 0)
                flag = 1;
        }
        if (flag == 0)
            printf("%s: %d\n", words[i], c);
    }
}
void BulidStr(char ***ptext, int *psize)//bulid the string
{
    char help[10];
    int len;
    printf("Enter count of words:\n");
    scanf("%d", psize);
    *ptext = (char **)calloc(*psize, sizeof(char *));
    getchar();
    for (int i = 0; i < *psize; i++)
    {
        fgets(help, 10, stdin);
        len = strlen(help);
        if (len > 0 && help[len - 1] == '\n')
            help[len - 1] = '\0';
        (*ptext)[i] = (char *)malloc(strlen(help + 1));
        strcpy((*ptext)[i], help);
    }
}
void BulidStrStop(char ***ptext, int *psize) // bulid the string of stop word
{
    char help[10];
    int len;
    printf("Enter count of words stops:\n");
    scanf("%d", psize);
    *ptext = (char **)calloc(*psize, sizeof(char *));
    getchar();
    for (int i = 0; i < *psize; i++)
    {
        fgets(help, 10, stdin);
        len = strlen(help);
        if (len > 0 && help[len - 1] == '\n')
            help[len - 1] = '\0';
        (*ptext)[i] = (char *)malloc(strlen(help + 1));
        strcpy((*ptext)[i], help);
    }
}
void smallleter(char ***text, int countword) // change the capital letter to small .
{
    for (int i = 0; i < countword; i++)
    {
        for (int j = 0; j < strlen((*text)[i]); j++)
        {
            if ((*text)[i][j] >= 'A' && (*text)[i][j] <= 'Z')
                (*text)[i][j] += diff;
        }
    }
}
int CheckNum(char *word) // checking the word if it contain number or no.
{
    for (int i = 0; i < strlen(word); i++)
        if (word[i] >= '0' && word[i] <= '9')
            return 0;
    return 1;
}

void prepocessing(char ***text, int *countword, char **stopwords, int countstopwords) // checking the words between the stop word and the text and update the text after removinh the similar words. 
{

    int i, j, c = 0, count = *countword;
    int flag = 0, x;
    char **str;
    smallleter(text, *countword);
    smallleter(&stopwords, countstopwords);
    for (i = 0; i < *countword; i++)
    {
        for (j = 0; j < countstopwords; j++)
        {
            if (strcmp((*text)[i], stopwords[j]) == 0 || CheckNum((*text)[i]) == 0)
                count--;
        }
    }
    str = (char **)calloc(count , sizeof(char *));

    for (i = 0; i < *countword; i++)
    {
        flag = 0;
        for (j = 0; j < countstopwords ; j++)
        {
            x = strcmp((*text)[i], stopwords[j]);
            if (x == 0|| CheckNum((*text)[j]) == 0)
                flag = 1;
        }    
        if (flag == 0)
        {
            str[c] = (char *)malloc(strlen((*text)[i]) + 1);
            strcpy(str[c], (*text)[i]);
            c++;
        }
    }
*countword=count;
    *text = str;
}
