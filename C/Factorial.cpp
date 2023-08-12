#include <stdio.h>
int fact(int a)
{
    if(a==0)
    	return 1;
    return a*fact(a-1);
}
int main()
{
	int num;
	printf("Enter a number:\n");
	scanf("%d",&num);
    printf("Factorial of %d is: %d",num,fact(num));
    return 0;
}
