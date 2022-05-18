/* Assignment: 1
campus: Beer Sheva 
auther:Ahmad Abomdegam ID:209101948
*/
#include<stdio.h>
#define max 99999
#define min 9999
int main ()
{
int number;
printf("Enter the number: \n");
scanf("%d",&number);
if(number<max && number>min && number%10!=0 && number/10%10!=0 && number/100%10!=0 && number/1000%10!=0 && number/10000!=0)
{
if(number%10==number/10000 && number/10%10==number/1000%10)
printf("the number is plendrom.\n");
else printf("the number is not plendrom !!\n");
}
else printf("is invalid !! \n");

return 0;
} 
