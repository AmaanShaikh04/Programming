#include <stdio.h>
int getMax(int arr[],int n)
{
    int max=arr[0];
    int i;
    for (i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
void countSort(int arr[],int n,int exp)
{
	int op[n];
    int i,c[10]={0};
    for (i=0;i<n;i++)
        c[(arr[i]/exp)%10]++;
    for (i=1;i<10;i++)
        c[i]+=c[i-1];
    for (i=n-1;i>=0;i--)
	{
        op[c[(arr[i]/exp)%10]-1]=arr[i];
        c[(arr[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        arr[i]=op[i];
}
void radixsort(int arr[],int n)
{
    int m=getMax(arr,n);
    int i;
    for(i=1;m/i>0;i*= 10)
        countSort(arr,n,i);
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int main()
{
    int arr[]={170,45,75,90,802,24,2,66};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixsort(arr,n);
    print(arr,n);
    return 0;
}
