#include <stdio.h>
int main()
{
	int arr[100],c,first,last,mid,n,search;
	printf("Enter no of elements\n");
	scanf("%d",&n);
	printf("Enter array elements\n");
	for(c=0;c<n;c++)
	scanf("%d",&arr[c]);
	printf("Enter value to be searched\n");
	scanf("%d",&search);
	first=0,last=n-1,mid=(first+last)/2;
	while(first<=last)
	{
		if(arr[mid]<search)
		first=mid+1;
		else if(arr[mid]==search)
		{
			printf("%d found at location %d\n",search, mid+1);
			break;
		}
		else 
		last=mid-1;
		mid=(first+last)/2;
	}
	if(first>last)
	printf("%d is not in the list\n",search);
	return 0;
}
