#include <stdio.h>
int main()
{
    int i,m,n,exp,arr[100];
    printf("Enter number of elements");
    scanf("%d",&n);
    printf("Enter array elements");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    m=arr[0];
    for (i=1;i<n;i++)
	{
    	if(arr[i]>m)
    	m=arr[i];
	}
    for(i=1;m/i>0;i*=10)
	{
		int o[n];
    	int i,c[10]={0};
    	for (i=0;i<n;i++)
        c[(arr[i]/exp)%10]++;
    	for (i=1;i<10;i++)
        c[i]+=c[i-1];
    	for (i=n-1;i>=0;i--)
		{
        o[c[(arr[i]/exp)%10]-1]=arr[i];
        c[(arr[i]/exp)%10]--;
    	}
    	for(i=0;i<n;i++)
        arr[i]=o[i];
	}
    for(i=0;i<n;i++)
    printf("%d\n",arr[i]);
    return 0;
}
