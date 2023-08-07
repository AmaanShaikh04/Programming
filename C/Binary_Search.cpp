#include<stdio.h>
int main()
{
    int arr[5]={1,2,7,23,45},i,n=5,num=2,flag=0,f,l,mid,c;
    f=0;
    l=n-1;
    mid=f/l;    
if(arr[mid]>num)
{
  for(i=mid+1;i<5;i++)
  {
    if(num==arr[i])
    {
      flag=1;
      c=i+1;
      break;
    }
  }
}else if(arr[mid]<num)
{
  for(i=0;i<5;i++)
  {
    if(num==arr[i])
    {
      flag=1;
      c=i+1;
      break;
    }
  }
}
    if(flag==1)
        printf("\nElement %d found at position %d",num,c);
    else
        printf("\nElement not found");
    return 0;
}
