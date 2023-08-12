#include <stdio.h>

int main()
{
	int a,b,c;
	printf("Enter num1: ");
	scanf("%d",&a);
	printf("Enter num2: ");
	scanf("%d",&b);
	c=a%b;
	printf("Remainder: %d",c);
	return 0;
}
