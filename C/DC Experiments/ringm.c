#include <stdio.h>

#define MAX 10

int processes[MAX], n;
int status[MAX];

void ringElection(int initiator) {
    int elected = initiator;
    int current = initiator;
    
    printf("\nElection started by process %d\n", processes[initiator]);
    
    do {
        current = (current + 1) % n;  // Move to the next process in the ring
        if (processes[current] != -1 && status[current] != 0) {
            printf("Process %d[E] passes message to Process %d\n", processes[elected], processes[current]);
            if (processes[current] > processes[elected]) {
                elected = current;
            }
        }
    } while (current!=initiator);

    printf("\nProcess %d is elected as the new coordinator!\n", processes[elected]);
    
    while (1) {
        current = (current + 1) % n;  // Move to the next process in the ring
        if (processes[current] != -1 && status[current] != 0) {
            if (processes[current] == processes[elected]) {
                break;
            } else {
                printf("Process %d[C] passes message to Process %d\n", processes[elected], processes[current]);
            }
        }
    }
}

void initializeProcesses() {
    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &processes[i]);
        status[i] = 1;
    }
}

void setFaultyNodes() {
    int faulty, f, i,j;
    printf("Enter the number of faulty nodes: ");
    scanf("%d", &faulty);
    
    for (j = 0; j < faulty; j++) {
        printf("Enter the faulty node ID: ");
        scanf("%d", &f);
        for (i = 0; i < n; i++) {
            if (processes[i] == f) {
                status[i] = 0;
                break;
            }
        }
    }
}

void startElection() {
    int initiator, initiatorIndex = -1;
    printf("Enter the initiator process ID: ");
    scanf("%d", &initiator);
    int i;
    
    for (i = 0; i < n; i++) {
        if (processes[i] == initiator) {
            initiatorIndex = i;
            break;
        }
    }
    
    if (initiatorIndex == -1 || status[initiatorIndex] == 0) {
        printf("Invalid initiator ID!\n");
    } else {
        ringElection(initiatorIndex);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nRing Election Algorithm Menu\n");
        printf("1. Initialize Processes\n");
        printf("2. Set Faulty Nodes\n");
        printf("3. Start Election\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                initializeProcesses();
                break;
            case 2:
                setFaultyNodes();
                break;
            case 3:
                startElection();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

