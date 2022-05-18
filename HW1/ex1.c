/* Assignment:1
campus: Beer Sheva 
auther : Ahmad abomdegam ID:209101948
*/
#include<stdio.h>
#define hour 60
int main ()
{
float time;
int speed,distance;
printf("Enter the distance and the speed:\n");
scanf("%d%d",&distance,&speed);
time=(float)(distance*hour)/speed;
printf("the time is:%.2f in minutes\n",time);
return 0;
}

