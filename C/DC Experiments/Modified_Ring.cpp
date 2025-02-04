#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int id;
    bool alive;
    struct node* next;
};

struct node* head = NULL;

void create() {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    printf("Enter Process ID: ");
    scanf("%d", &p->id);
    p->alive = true;
    p->next = NULL;

    if (head == NULL) {
        head = p;
        p->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = p;
        p->next = head;
    }
}

void display() {
    if (head == NULL) {
        printf("No processes in the ring.\n");
        return;
    }
    struct node* temp = head;
    do {
        printf("Process ID: %d, Status: %s\n", temp->id, temp->alive ? "Alive" : "Faulty");
        temp = temp->next;
    } while (temp != head);
}

void report_faulty() {
    int id;
    printf("Enter Process ID to report as faulty: ");
    scanf("%d", &id);
    struct node* temp = head;
    do {
        if (temp->id == id) {
            temp->alive = false;
            printf("Process %d marked as faulty.\n", id);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Process ID %d not found.\n", id);
}

void initiate_election() {
    if (head == NULL) {
        printf("No processes in the ring.\n");
        return;
    }

    int initiator;
    printf("Enter Process ID to initiate the election: ");
    scanf("%d", &initiator);
    
    struct node* temp = head;
    struct node* initiator_node = NULL;
    
    do {
        if (temp->id == initiator) {
            initiator_node = temp;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (initiator_node == NULL) {
        printf("Process ID %d not found in the ring.\n", initiator);
        return;
    }
    
    if (!initiator_node->alive) {
        printf("Initiator process %d is faulty and cannot start the election.\n", initiator);
        return;
    }
    
    int max_id = initiator;
    temp = initiator_node->next;

    printf("Initiating election\n");
    printf("E|%d ", initiator);
    
    while (temp != initiator_node) {
        if (temp->alive) {
            if (temp->id > max_id) {
                max_id = temp->id;
            }
        }
        printf("-> E|%d ", max_id);
        temp = temp->next;
    }
    printf("-> Leader %d elected.\n", max_id);

    printf("Notifying all processes\n");
    temp = initiator_node->next;
    printf("C|%d ", max_id);
    while (temp != initiator_node) {
        if (temp->alive) {
            printf("-> C|%d ", max_id);
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Initialize the processes\n");
        printf("2. Report Faulty Nodes\n");
        printf("3. Initiate Election (Modified Ring Algorithm)\n");
        printf("4. Display Processes\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            create();
            break;
        case 2:
            report_faulty();
            break;
        case 3:
            initiate_election();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

