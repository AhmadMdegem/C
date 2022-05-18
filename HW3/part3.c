/*Assignment: 3
  Campus:Beer sheva
  Author: Israel, ID:209101948
*/

#include <stdio.h>
#define SIZE 80
typedef enum { FALSE,TRUE } Bool;
int CountWord(char []);
int Appear(int,int,char[]);
int Index(char[],int);
void FindSimilarWords(char[]);
int Strlen(char[]);
Bool StringChecker(char[]);
int main()
{
    char str[SIZE];
    printf("Enter string brackets: \n");
	fgets(str, SIZE, stdin); //recieve the string by fgets.
    int x = StringChecker(str); //takes value what Function stringcheacker return. 
    if (x == 0) 
        printf("Invalid string brackets.\n");
    else if (x == 1)
        printf("Valid string brackets.\n");
     printf("Enter Your text:\n");
     fgets(str,SIZE,stdin); //recieve the string by fgets.
     FindSimilarWords(str);

    return 0;
}

Bool StringChecker(char str[])

{
    int c = 0, i, k, flag = 1, size;
    
    size = Strlen(str); //variable takes length the string.
    
        for (i = 0; i < size; i++)
        {

            if (str[i] == '(')

                c++;

            if (str[i] == ')')

                c--;

            if (c<0) //if the brackets close before open illegal.
            
                flag = 0;
                
            if (str[i] != ')' && str[i] != '(') //illegal get out.
            
                flag = 0;
        }

    if (flag == 1)

        for (k = 0; k < size; k++)

        {

            if (str[k] == '(') //Delete the brackets i used by get you any char dont equal ( or ).

                str[k] = 'A';

            for (i = 1; i < size; i++)

                if (str[i] == ')') //Delete the brackets i used by get you any char dont equal ( or ).

                    str[i] = 'a';
        }

    if (flag == 0)

        return FALSE;

    if (flag == 1)

        return TRUE;
}
int Strlen(char str[SIZE]) //length the string.
{
    int count = 0, i;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i - 1;
}


 void FindSimilarWords(char str[]) 
  {
    int i,j,start1,start2,n,check,f,l,word=0;
     Bool flag=TRUE;
   
      for(i=1;i<=CountWord(str);i++) //works count word in the string.
        { 
		start1=Index(str,i);
           for(j=i+1;j<=CountWord(str);j++)
             { 
		 start2=Index(str,j);
                	flag=TRUE;
                 for(n=start1;str[n]!='\0'&&str[n]!=' '&&flag;n++)
                  {
                        check=Appear(n,start2,str); //check the letters by founction Apper.
                          if(check==0)
                             flag=FALSE;
				else flag=TRUE;
                     }
                       if(flag) //after the checks if all true printing it.
                         {
                           
                           for(l=start1;str[l]!=' '&&str[l]!='\0';l++)
                              printf("%c",str[l]);
				printf("  ");
                             for(f=start2;str[f]!=' '&&str[f]!='\0';f++)
                              printf("%c",str[f]);
				printf("\n");
					word++;
                         }
                   
                
            }
        }
                    if(word==0)
                       printf("There are no similar words.\n");
   }


int Index(char str[],int start) //helping to find the indexs i need it.
{
int m,space=0;
for(m=0;str[m]!='\0',space<start-1;m++)
   if(str[m]==' ')
      space++;
   return m;
}


int Appear(int index1,int index,char str[]) //checks the letters that recivied if appear in the word and returns appropriate answer. 
{
int g;
for(g=index;str[g]!='\0'&&str[g]!=' ';g++)
{ 
  if(str[index1]==str[g])
       return 1;
	if(str[index1]+32==str[g] || str[g]+32==str[index1]) //does no matter capital or small letters. 
	return 1;
}
return 0;
}

int CountWord(char str[]) //how much word in the string.
{
int i,count=1;
for(i=0;str[i]!='\0';i++) 
      if(str[i]==' ')
        count++;
return count;
}
