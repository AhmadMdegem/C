/*
Campus:‬‬ ‫‪ ‬ ‫‪Beer‬‬ ‫‪Sheva‬
auther:‬ahmad abomdegam ,‬‬ ‫‪ID:‬‬ ‫209101948

*/
#include <stdio.h>
 int main () {
  int  first_oper, second_oper; 
  char operation ;
  printf ("hey enter an operation (+,-,*,/,%%)\n");
  scanf(" %c",&operation); 
  if (!(operation=='+'||operation=='*'||operation=='-'||operation=='/'||operation=='%')){
   printf("your input is incorrect!");
  return 0;
 }
  printf("Enter first operand:\n");
  scanf("%d",&first_oper);
  printf("Enter second  operand:\n");
  scanf("%d",&second_oper);
  switch(operation)
  {
   case '+' :
    printf("iam a clever calcultoar:%d+%d=%d\n",first_oper,second_oper,first_oper+second_oper);
   break ;

   case '*' :
    printf("iam a clever calcultoar:%d*%d=%d\n",first_oper,second_oper,first_oper*second_oper);
   break ;

   case '/':
    if(second_oper!=0)
     printf("iam a clever calcultoar:%d/%d=%.2f\n",first_oper,second_oper,(float)first_oper/second_oper);
    else
     printf("no division with 0");
   break ;

   case '-':
     printf("iam a clever calcultoar:%d-%d=%d\n",first_oper,second_oper,first_oper-second_oper);
   break;

   case '%':
    if(second_oper!=0 )
     printf("iam a clever calcultoar:%d%%%d=%d\n",first_oper,second_oper,first_oper%second_oper);
    else
     printf("no modulo with 0");
   break ;
};
return 0;
}
