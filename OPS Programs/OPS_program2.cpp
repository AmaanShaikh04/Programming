//SJF


#include<stdio.h>
 int main()
{
    int b[10],p[10],w[10],tt[10],i,j,n,total=0,pos,temp;
    float avg_w,avg_tt;
    
    printf("Enter number of process:");
    scanf("%d", &n);
  
    printf("\nEnter Burst Time:\n");
    
	for(i = 0;i < n;i++)
    {
        printf("p%d:", i+1);
        scanf("%d", &b[i]);
        p[i] = i+1;         
    }
  
   //sorting of burst times
    for(i = 0;i < n; i++)
    {
        pos = i;
        for(j = i+1;j < n;j++)
        {
            if(b[j] < b[pos])
                pos = j;
        }
  
        temp = b[i];
        b[i] = b[pos];
        b[pos] = temp;
  
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    w[0] = 0;            
     
    for(i = 1;i < n;i++)
    {
        w[i] = 0;
        for(j = 0;j < i;j++)
            w[i] += b[j];
        total += w[i];
    }
  
    avg_w = (float)total / n;      
    total = 0;

	printf("-----------------------------------------------------------------");
    printf("\n|Process\t|Burst Time\t|Waiting Time\t|Turnaround Time|");
    printf("\n-----------------------------------------------------------------");
    for(i = 0;i < n;i++)
    {
        tt[i] = b[i] + w[i];   
        total += tt[i];
        printf("\n|p%d\t\t|%d\t\t|%d\t\t|%d\t\t|", p[i], b[i], w[i], tt[i]);
    }
    printf("\n-----------------------------------------------------------------");
    avg_tt = (float)total / n;    
    printf("\n\nAverage Waiting Time=%f", avg_w);
    printf("\nAverage Turnaround Time=%f", avg_tt);
}
