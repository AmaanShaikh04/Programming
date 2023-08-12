#include <stdio.h>
int main()
{
	int arr[20],brr[20],i,j,n=0;
	printf("Enter 20 array elements\n");
	for(i=0;i<20;i++)
	scanf("%d",&arr[i]);
	brr[n]=0;
	for(i=0;i<20;i+=4)
	{
		for(j=0;j<5;j++)
		{
		brr[n]+=arr[i+j];
		}
		n++;
	}
	for(j=0;j<4;j++)
	printf("%d ",brr[j]);
	return 0;
}
