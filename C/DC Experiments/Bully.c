#include <stdio.h>

void initialize(int n, int pr[]);
void report_faulty(int n, int pr[], int faulty[]);
void display_processes(int n, int pr[], int faulty[], int coordinator);
void initiate_election(int n, int pr[], int faulty[], int *coordinator);

int define() 
{
    int n_id;
    printf("Enter number of Processes:\n");
    scanf("%d", &n_id);
    return n_id;
}

void initialize(int n,int pr[]) 
{
	int i;
    for (i=0;i<n;i++) 
	{
        printf("Enter Process ID for Process %d: ", i+1);
        scanf("%d", &pr[i]);
    }
}

void report_faulty(int n,int pr[],int faulty[]) 
{
    int count,fault_id,i,j;
    printf("Enter number of faulty nodes: ");
    scanf("%d", &count);
    for(i=0;i<count;i++) 
	{
        printf("Enter Faulty Process ID %d: ", i+1);
        scanf("%d", &fault_id);
        for(j=0;j<n;j++) 
		{
            if(pr[j]==fault_id) 
			{
                faulty[j]=1;
                break;
            }
        }
    }
}

void display_processes(int n,int pr[],int faulty[],int coordinator) 
{
    printf("\nProcess Status:\n");
    int i;
    for(i=0;i<n;i++)
	{
        printf("Process ID %d - %s\n", pr[i], faulty[i] ? "Faulty" : "Active");
    }
    printf("Current Coordinator: %d\n", coordinator);
}

void initiate_election(int n, int pr[], int faulty[], int *coordinator) 
{
    int initiator,i;
    printf("Enter the initiator process ID: ");
    scanf("%d", &initiator);

    int found=0,initiator_index=-1;
    for(i=0;i<n;i++)
	{
        if(pr[i]==initiator && !faulty[i]) 
		{
            found=1;
            initiator_index=i;
            break;
        }
    }

    if(!found)
	{
        printf("Invalid or faulty initiator.\n");
        return;
    }

    printf("\nElection initiated by Process %d\n", initiator);

    int new_coordinator=-1;

    for(i=initiator_index+1;i<n;i++)
	{
        if(!faulty[i])
		{
            printf("Process %d sends election message to Process %d\n", pr[initiator_index], pr[i]);
            printf("Process %d replies to Process %d\n", pr[i], pr[initiator_index]);
            if (pr[i] > new_coordinator)
			{
                new_coordinator = pr[i];
            }
        } else {
            printf("Process %d sends election message to Process %d - No response (Faulty)\n", pr[initiator_index], pr[i]);
        }
    }

    if (new_coordinator == -1) 
	{
        *coordinator = initiator;
    } else {
        *coordinator = new_coordinator;

        for ( i = 0; i < n; i++) 
		{
            if (!faulty[i]) 
			{
                printf("Process %d receives coordinator message: New Coordinator is Process %d\n", pr[i], *coordinator);
            }
        }
    }

    printf("\nNew Coordinator is Process %d\n", *coordinator);
}


int main() 
{
    int ch, n = 0, coordinator = -1;
    int pr[100];
    int faulty[100] = {0};

    while (1) 
	{
        printf("\n1. Define the number of processes\n");
        printf("2. Initialize the processes\n");
        printf("3. Report Faulty Nodes\n");
        printf("4. Initiate Election (Bully Algorithm)\n");
        printf("5. Display Processes\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1:
                n = define();
                break;
            case 2:
                initialize(n, pr);
                break;
            case 3:
                report_faulty(n, pr, faulty);
                break;
            case 4:
                initiate_election(n, pr, faulty, &coordinator);
                break;
            case 5:
                display_processes(n, pr, faulty, coordinator);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
