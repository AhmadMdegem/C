/* 
assignment :5
campus : beer sheva,israel
auther: ahmad abo mdegam
id:209101948
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct {
int hours;
int minutes;
int seconds;
}TaskTime;

typedef struct {
char name[SIZE+1];
char id[SIZE];
TaskTime time;

}Marathon;

int Countofplayers(char*  file);
void buildinformation(Marathon**players,int size,char*TextName1);


int main()
{
    char filesname1[2*SIZE],filesname2[2*SIZE];
    printf("Enter the name of the input text\n");
    scanf("%s",filesname1);
    printf("Enter the name of the output text\n");
    scanf("%s",filesname2);




    return 0;
}




int Countofplayers(char*  TextName1) //how mony players in the files
{
FILE* input=NULL;
char letter;
int count=0;
input=fopen(TextName1,"r");
    if(input==NULL)
    {
    printf("ERROR\n");
exit(1);
    }
fscanf(input,"%c",&letter);//resive from the files and check
while(!feof(input))
{
if(letter=='\n')//count of \n is count of the players 
count++;
fscanf(input,"%c",&letter);


}
fclose(input);//close the files
return count;
}

void buildinformation(Marathon**players,int size,char*TextName1)//fill the information of the players by the files
{
FILE* input=NULL;
*players=(Marathon*)malloc(size*sizeof(Marathon));
if(*players==NULL)
{
    printf("ERROR\n");
exit(1);

}
input=fopen(TextName1,"r");//to read information from the files
    if(input==NULL)
    {
    printf("ERROR\n");
exit(1);
    }

while(!feof(input))//end of files
{
fscanf(input,"%s%s%d%d%d",(*players)->name,(*players)->id,&(*players)->time.hours,&(*players)->time.minutes,&(*players)->time.seconds);//fill information to the struct by the file

}

}
void faster(Marathon *players,int size)//to know who the faster between the players
{
int max;
max=players->time.hours;
for(int i=1;i<size;i++)
{
if(players+i->time.hours<max)
if(players+i->time.hours==max)
if(players+i->time.minutes<max)
if(players+i->time.suconds<max)





}



