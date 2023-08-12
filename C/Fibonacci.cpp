#include<stdio.h>
int Fibo(int);
int main()
{
   int no,i;
   printf("Enter limit\n");
   scanf("%d",&no);
   printf("Fibonacci series:\n");
   for(i=0;i<=no;i++)
   {
    	printf("%d\n",Fibo(i));
   }
   return 0;
}
int Fibo(int x)
{
   if(x==0)
    	return 0;
   else if(x==1)
    	return 1;
   else
    	return(Fibo(x-1)+Fibo(x-2));
}
