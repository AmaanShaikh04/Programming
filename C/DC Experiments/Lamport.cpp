#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct 
{
    int process_id;
    int logical_clock;
} Process;

void send_event(Process *sender, Process *receiver) 
{
    sender->logical_clock++;  // Increment sender clock before sending
    receiver->logical_clock = (receiver->logical_clock > sender->logical_clock) 
                                ? receiver->logical_clock + 1 
                                : sender->logical_clock + 1;
    printf("Process %d sent a message to Process %d. Clocks: P%d = %d, P%d = %d\n",
           sender->process_id, receiver->process_id,
           sender->process_id, sender->logical_clock,
           receiver->process_id, receiver->logical_clock);
}

void internal_event(Process *p) 
{
    p->logical_clock++;
    printf("Process %d performed an internal event. Clock = %d\n", p->process_id, p->logical_clock);
}

int main() 
{
    Process P1 = {1, 0};
    Process P2 = {2, 0};
    Process P3 = {3, 0};

    internal_event(&P1);
    send_event(&P1, &P2);
    internal_event(&P2);
    send_event(&P2, &P3);
    internal_event(&P3);
    send_event(&P3, &P1);

    printf("Final Clocks: P1 = %d, P2 = %d, P3 = %d\n", P1.logical_clock, P2.logical_clock, P3.logical_clock);

    return 0;
}

