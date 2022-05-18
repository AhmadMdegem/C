/* Assignment:1
campus: Beer Sheva 
auther : Ahmad abomdegam  ID:209101948
*/
#define digit1 9
#define digit_1 -9
#define digit2 99
#define digit_2 -99
#define digit3 999
#define digit_3 -999
#define digit4 9999
#define digit_4 -9999
#include<stdio.h>
int main ()
{
int number;
printf("Please Enter The Number :\n");
scanf("%d",&number);
if(number<=digit1 && number>=digit_1)
{
printf("The number of digits is : 1\n");
if(number%2==0 && number>0)
printf("And the number is Evin.\n");
if(number%2!=0 && number>0)
printf("And the number is Ood.\n");
if(number<0)
printf("The quardratic number is %.1d\n\n",number*number);
}
else if(number>digit1 && number<=digit2 || number<digit_1 && number>=digit_2)
{
printf("The number of digits is : 2\n");
if(number%2==0 && number>0)
printf("And the number is Evin.\n");
if(number%2!=0 && number>0)
printf("And the number is Ood.\n");
if(number<0)
printf("The quardratic number is %.1d\n\n",number*number);
}
else if(number>digit2 && number<=digit3 || number<digit_2 && number>=digit_3)
{
printf("The number of digits is : 3\n");
if(number%2==0 && number>0)
printf("And the number is Evin.\n");
if(number%2!=0 && number>0)
printf("And the number is Ood.\n");
if(number<0)
printf("The quardratic number is %.1d\n\n",number*number);
}
else if(number>digit3 && number<=digit4 || number<digit_3 && number>=digit_4)
{
printf("The number of digits is : 4\n");
if(number%2==0 && number>0)
printf("And the number is Evin.\n");
if(number%2!=0 && number>0)
printf("And the number is Ood.\n");
if(number<0)
printf("The quardratic number is %.1d\n\n",number*number);
}
else if(number>digit4 || number<digit_4) 
printf("Only Enter Number Up To Fuor Digits !!\n");
return 0;
}

