//accept marks of 10 students out of 100 and sort
#include <stdio.h>

int MAX=100;

void buck(int arr[10], int n)
{
	int i,j;
	int b[MAX];
	for(i=0; i<MAX; i++)
		b[i]=0;
	for(j=0; j<n; j++)
		b[arr[j]]++;
	for(i=0, j=0; i<MAX; i++)
	{
		for(;b[i]>0;b[i]--)
		{
			arr[j]=i;
			j++;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[10],i,n=10;
	printf("Enter Marks out of 100:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>100)
		{
			printf("Wrong Input\n");
			return 0;
		}
	}
	buck(arr,n);
	return 0;
}
