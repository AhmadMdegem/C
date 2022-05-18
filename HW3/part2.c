/*Assignment: 3
  Campus:Beer sheva
  Author: Israel, ID:209101948
*/

#include<stdio.h>
#define SIZE 3
int AllRings(int [][SIZE]);
int Ringcount();
void scanner(int ar[][SIZE]);
int Ring(int ar[][SIZE],int id);
int main()
{
int id;
int res=0,Matrix[SIZE][SIZE];
scanner(Matrix); //recive the element of the matrix.
printf("Please enter your id:\n");
scanf("%d",&id);
if(id>=0&& id<Ringcount())  //check the id legall or not .
{
res=Ring(Matrix,id); // variable res takes value of Ring she returns.
printf("The sum of ring %d is: %d\n",id,res);
}
else 
printf("Number is illegal!!\n");
printf("The sum of all Rings is: %d\n",AllRings(Matrix)); //printing the sum of all Rings in the matrix.

return 0;
}
void scanner(int Matrix[][SIZE]) // Function helping to recevied elements of matrix.
{
int i,j;
printf("Please Enter the elements of the Matrix:\n");
for(i=0;i<SIZE;i++)
for(j=0;j<SIZE;j++)
{
printf("Enter the value to Matrix[%d][%d]: ",i,j);
scanf("%d",&Matrix[i][j]);
}
}//end

int Ring(int Matrix[][SIZE],int id) // Function sum of ring you gives it id.
{
int j,sum=0;
if(id!=Ringcount()-1)
{
for(j=id;j<SIZE-id;j++) //sum of external ring.
{
sum+=Matrix[id][j];
sum+=Matrix[j][id];
sum+=Matrix[SIZE-id-1][j];
sum+=Matrix[SIZE-j-1][SIZE-1-id];
}
sum=sum-Matrix[id][id]-Matrix[id][SIZE-1-id]-Matrix[SIZE-1-id][id]-Matrix[SIZE-1-id][SIZE-id-1]; //the common loser.
return sum;
}
else if(SIZE%2==1) // sum of the inner ring.(odd matrix 5,3,7...)
 return Matrix[id][id];
else 
return Matrix[id][id]+Matrix[id][id+1]+Matrix[id+1][id]+Matrix[id+1][id+1]; // sum of the inner ring.(even matrix 2,4,6...)

}//end

int Ringcount() //Function how much rings in the matrix.
{
int i,count=0;
for(i=0;i<SIZE;i+=2)
count++;
 return count;
}//end 
int AllRings(int Matrix[][SIZE]) // Function sum of all rings in the matrix.
{
	int i,sum=0;
for(i=0;i<Ringcount();i++)
sum+=Ring(Matrix,i);;
return sum;
}

