/*Assignment: 3
  Campus:Beer sheva
  Author: Israel, ID:209101948
*/

#include<stdio.h>
#define N 14
#define M 10
void Scanner(int[],int);
void PrintMaxPalindrom(int [],int);
int PrintDivided(int [],int, int);
int main()
{
int value,ar[N],x,arr[M];
Scanner(ar,N);
printf("Enter the value:\n");
scanf("%d",&value);
x=PrintDivided(ar,N,value);
printf("%d\n",x); 
Scanner(arr,M);
PrintMaxPalindrom(arr,M);
return 0;
}
int PrintDivided(int ar[],int size,int value) //Function recivied array and value, divide the elements by value that have modolo 0 returns how much elements and printing it.
{
	int i,count=0;
	if(value!=0){
	printf("the numbers that divided by the value is:");
	for(i=0;i<size;i++)
	if(ar[i]%value==0)
	{
		printf("%d ",ar[i]);
		count++;
	}	
		printf("\nThe count of the numbers that divided by value is:");
		return count;
}
else
 return -1;
}
void Scanner(int ar[],int size) //Function helping to recive the elements.
{
int i;
printf("Enter elements of the:\n");
for(i=0;i<size;i++){
printf("Enter element of the ar[%d]:\n",i);
scanf("%d",&ar[i]);
}
}//end scanner

void PrintMaxPalindrom(int ar[],int size)
{
int i,flag=0,a,b;

int j,k,savei=0,savej=0,c=0,max=0,temp=0;

for(i=0;i<size;i++) 
{
	for(j=size-1;j>i;j--) //To check the numbers in place i where it availiable
 {
		if(ar[i]==ar[j]) 
	{
		flag=1; 
		a=i;    //takes value of i and j to variables differnt to save and dont change it.  
		b=j;
	}
		else flag=0;
  		 while(flag!=0&&b>=a) //goes on all numbers between the i and j that have same value.
		{
    		a++;
    		b--;
    		if(ar[a]==ar[b])
			    flag=1;
		    else flag=0;
  		}
		if(flag==1)
   	  {
		c=0;
    	for(k=i;k<=j;k++)
		c++;
		if(c>max) //save the max palindrom.
	  {
		max=c;
		savei=i;
		savej=j;
	  }
	}
  }
}
		if(max>c)
	{	
	printf("The max palindrom is: \n");
	 for(k=savei;k<=savej;k++) //printing the max palindrom that i save there indexs.
  	  printf("%d",ar[k]);
		temp=1;	
	}
    		printf("\n");
	
	if(temp!=1)
	printf("No Palindrom exist\n");


}
