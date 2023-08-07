//RR


#include <stdio.h>
int main()
{
	int i, n, te, t, at[10], bt[10], temp[10];
	int sum=0,count=0, wt=0, tat=0;
	double avg_wt, avg_tat;
	printf("Experiment done by Amaan Shaikh roll no 28\n\n");
	printf("Enter Total number of process: ");
	scanf("%d", &n);
	te=n;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the Arrival and Burst time of the Process no [%d]\n", i+1);
		scanf("%d", &at[i]);
		scanf("%d", &bt[i]);
		temp[i] = bt[i];
	}
	
	printf("Enter the Time quantum:");		//time for which a process is allowed to run
	scanf("%d", &t);
	printf("Process No \t\t Burst Time \t\t Turn around time \t Waiting Time ");
	
	for(sum=0,i=0;te!=0;)
	{
		if(temp[i]<=t && temp[i]>0)
		{
		    sum = sum + temp[i];		//using sum variable to calculate completion time
		    temp[i] = 0;
		    count=1;
		}
		else if(temp[i]>0)
		{
		    temp[i] = temp[i] - t;
		    sum = sum + t;
		}
		if(temp[i]==0 && count==1)
		{
		    te--;
		    															//tat=completion time - arrival time
		    															//wt=tat-burst time
		    printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);
		    wt = wt+sum-at[i]-bt[i];
		    tat = tat+sum-at[i];
		    count = 0;
		}
		if(i==n-1)
		{
		    i=0;
		}
		else if(at[i+1]<=sum)
		{
			i++;
		}
		else
		{
		    i=0;
		}
	}
	
	printf("\n\n");
	avg_wt = wt * 1.0/n;
	avg_tat = tat * 1.0/n;
	printf("Average Turn Around Time: %lf\n", avg_tat);
	printf("Average Waiting Time: %lf\n", avg_wt);
	return 0;
}
