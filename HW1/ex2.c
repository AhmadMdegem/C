/* Assignment: 1
campus: Beer Sheva 
auther: Ahmad Abo mdegam, ID: 209101948
*/
#define fuel_98 7.8
#define fuel_95 6.25
#define solar 5.97
#define max 150
#include <stdio.h>
int main()
{
    float liters,payment;
    char answer; //מגדיר משתנה מסוג char  
    printf("Enter Your Tybe :\n fouel_98 Enter s OR S.\n fuel_95 Enter R OR r.\n solar Enter D OR d.\n if you dont want anything please Enter X .\n");
    scanf("%c",&answer);
    if(answer=='s' || answer=='S')
{
    printf("How many liters you want?\n");
    scanf("%f",&liters);
    payment=liters*fuel_98;
    printf("Your payment is %.2f\n",payment);
    if(payment > max)
    printf("You won a free newspaper.\n");
 }
 else if(answer=='D' || answer=='d')
{
    printf("How many liters you want?\n");
    scanf("%f",&liters);
    payment=liters*solar;
    printf("Your payment is %.2f\n",payment);
    if (payment > max)
    printf("You won a free newspaper.\n");
 }
 else if(answer=='R' || answer=='r')
{
    printf("How many liters you want?\n");
    scanf("%f",&liters);
    payment=liters*fuel_95;
    printf("Your payment is %.2f\n",payment);
    if(payment > max)
    printf("You won a free newspaper.\n");
 }
    else if(answer=='X')
    printf("Thank you.\n");
    else printf("Is invalid!!\n");
    
    return 0;
}