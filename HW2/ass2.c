/* Assignment: 2
Campus: Beer Sheva
Author: Ahmad Abu Mdegam
ID: 209101948 */
#include<stdio.h> 

 void CountIntersectDigits();

 void PrintFriends();

 long ReverseAndAdd5(long);

 void RemoveMaxDigit(long);

 void PrintSpecialNumbers();

 int MakeNewNumber(int,int);

 int Printpattern(int);


int main(){

int  choose,number6,number8;

long number4,number7,number3;

	printf("please select function:\n1- Same digits. \n2- Friends numbers. \n3- Reverse the digits and add 5. \n4- Remove all max digit. \n5- Print the special numbers. \n6- Make a new number. \n7- Print numbers in a pattern. \n8- Exit.\n ");

 	printf("Your choose is :\n");

  	scanf("%d",&choose);


  switch(choose)

{


 case 1:


     CountIntersectDigits();


	break;



 case 2:

 

          PrintFriends();


    

	break;





 case 3:

    

           ReverseAndAdd5(number3);

           

	break;


 case 4:

	

   RemoveMaxDigit(number4);

 

	break;




 case 5:


     PrintSpecialNumbers();


  	break;


 case 6:

    

	MakeNewNumber(number6,number8);

	

	break;


 case 7:


	Printpattern(number7);		

		

	break;


 case 8:


		printf("Exit\n");


	break;

}

}//end main.


int count(int,int); //helping function that return the count of equal numbers

void CountIntersectDigits()

{

    int num1,num2;

    int res=0;

    do{

    printf("Enter two numbers\n");

    scanf("%d%d",&num1,&num2);

    res=count(num1,num2);

    printf("the res is %d\n",res);

    res=0;

    }while(num1>0&&num2>0);

      

}

int count(int num1,int num2)

{

    int count=0,temp;

    temp=num2;

    

    while(num1!=0)

    {

        while(num2!=0)

        {

            if(num1%10==num2%10)

            count++;

            num2=num2/10;

        }

        num1=num1/10;

        num2=temp;

    }

    return count;

}//end1


/*ex2 The function print the friends numbers sum of first number divide equal the sucend number*/

void PrintFriends()

{

const int Max=1000; //fixed variable.

int i,j,d,num,sum;

 for(i=1;i<=Max;i++) //run for all the numbers between 1 to max.

	{

		sum=0;

		num=0;

	for(j=1;j<i;j++) //recieve i and start to devide all number between 1 to i.

	{

		if(i%j==0)   

			sum+=j; // if the i mod j equal zero plus j to sum.

	}

		sum;

	for(d=1;d<sum;d++)  // d varible start from 1 to sum(recieve it from for).

	{

		if(sum%d==0)

			num+=d; // if sum mod d equal zero plus d to num.

	}

		num;

		if(num==i)  //check if num(sum all the number they achieve the condition) equal i (the number).

	printf("%d %d\n",sum,num);

	}

	}//end2.

	

long Revers(long);

long Revers(long num) //Function helped get the number  and return revers of it.

{

    int sum=0;

    while(num>0) //checks if the number biger than zero.

    {

        sum=(sum+num%10)*10; // start to change the place of digit ( the first in the end).

        num/=10;

    }

    return sum/10;

}

long ReverseAndAdd5(long num)

{

    long res;

    printf("Enter number:\n");

    scanf("%ld",&num); // recieve number 

    res=Revers(num); // enters the number in function helped to revers the number.

    printf("The reverse of number is %ld+5=%ld\n",res,res+5); //printed the result plus 5.

}//end3.


/* ex4.c  the function remove the max digit of the number and print it after delete the max digit */

void RemoveMaxDigit(long num)

	{

int max=0,temp,sum=0,i=1;

	printf("Enter number\n");

	scanf("%ld",&num);   //recieve number .

	temp=num;

	while(num!=0) //if the number is not equal zero enter to while.

	{

		if(num%10>max) // checks tha max digit in the number and save it in varible max.

		max=num%10;

		num=num/10;

	}

	num=temp; // varible return the vale num.

	while(num!=0) 

	{

		if(num%10!=max) // check if the digit not equal max .

	{

		sum=sum+(num%10)*i; 

		i*=10;

	}

		num=num/10;

	}

	printf("the new number is %d\n",sum);

	}//end4.

	

/* ex5.c the function prints all special numbers have 5 digits.*/

void PrintSpecialNumbers()

{

const int min=10000; // fixed variable.

const int max=100000;  // fixed variable.

int i, digit, num1, num,flag=0,count=0;

	for (i = min; i < max; i++) // run between min to max .

	{

		num = i; digit = i; num1= i; // 3 variable recieve the value of i.

			flag = 0; // variable helped.

		while (digit!= 0) 

		{

			num = digit% 10; 

			num1= digit/ 10;

			while (num1!= 0 && flag == 0)        //passes on all digit of the number. 

		    {     

				if(num == num1% 10)

				flag = 1;


				num1= num1/ 10;

			}

			digit = digit/ 10;

		}


		if (flag == 0)

		{

			count++;

			printf("%d ",i);

		}

	}

	printf("\nthere are %d special numbers that have 5 digits",count);

}//end5.


/* ex6.c the function receives 2 numbers and makes a new number that contains the Maximum digits of both numbers */

int MakeNewNumber(int num1,int num2)

{

int i=1,sum=0;

	printf("Enter two numbers\n");

	scanf("%d%d",&num1,&num2); // receive 2 numbers.

	while(num1>0 && num2>0) // checks if 2 numbers not equal zero enter to while.

	{

		if(num1%10>num2%10)		//checks if num1 mod 10 biger the num2 mod 10.

		sum=sum+((num1%10)*i);  //num1 mod 10 multiply i enter to sum.

		else

		sum=sum+((num2%10)*i);

		num1=num1/10;

		num2=num2/10;

		i=i*10; // i variable every time multiply it 10 and save i.

	}	


		if(num1>num2) //checks if num1 biger the num2.

	{                                   

		while(num1!=0)

	{

		sum=sum+(num1%10)*i; // num1 mod 10 multiply i enter to sum.

		i=i*10;	

		num1=num1/10;		

 	}

	}

		else if(num1<num2) // checks if num2 biger than num1.

	{

		while(num2!=0)

	{

    	sum=sum+((num2%10)*i); //num2 mod 10 multiply i enter to sum.

		i=i*10;

		num2=num2/10;

	}

	}

		printf("%d\n",sum);

		

		return 0;

}//end6.


/* ex7.c the function receive number and print pattern */

int Printpattern(int num)

{

int row,i,j;

	printf("Enter number: \n");

	scanf("%d",&num); //recieve number.

	for(row=1;row<=num;row++) // run between variable row equal 1 to variable row equal number.

	{

	for(i=1;i<=num;i++)  // run between i equal 1 to i equal number.

	{

		if(i<=row) // checks if i smaller than variable row.

		printf("%d",i);

	}

	for(j=(num-row)*2;j>0;j--) // run between j equal number menos row multiply 2 to j biger than zero.

	printf(" ");

	for(int a=row;a>0;a--) 

	{

		if(a<=row) //checks if the variabl a smaller than variable row.

		printf("%d",a);

		}

		printf("\n");

	}

return 0;

}//end7.