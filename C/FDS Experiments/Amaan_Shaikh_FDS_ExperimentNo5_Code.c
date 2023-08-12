

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node {
int PRN;
char Name[10];
    struct node *next;
};

void createnode(struct node *head){
struct node *temp =head;
int PRN;
char Name[10];
char choice;

if(head==NULL){
printf("Memory is not allocated");
}
else {
do{
   struct node *curr =(struct node *)malloc(sizeof(struct node));
printf("Enter PRN Number and Name of Student : \n");
scanf("%d %s",&PRN,Name);
curr->PRN=PRN;
strcpy(curr->Name,Name);
curr -> next= NULL;
temp -> next=curr;
temp=curr;
printf("\nDo you want to add another node ( y/n )? \n");
scanf(" %c",&choice);
 }while(choice=='y');
}
}

void display(struct node *head){
 printf("\n\tPRN\t\t Name");
if(head->next==NULL){
printf("List is empty");
}
else{
struct node *curr;
curr=head->next;
while(curr!=NULL){
printf("\n%d %s",curr->PRN,curr->Name);
curr=curr->next;
}

}
}

int len(struct node *head){
struct node *curr;
int i=0;
curr=head->next;
while(curr!=NULL){
i++;
curr=curr->next;
}
return i;
}

void insert(struct node *head){
    int pos,k,i=1;
    int PRN;
    char Name[10];
    struct node *curr =(struct node *)malloc(sizeof(struct node));
    curr=head;
    struct node *nnode =(struct node *)malloc(sizeof(struct node));
    printf("Enter PRN Number and Name of Student : \n");
    scanf("%d %s",&PRN,Name);
    nnode->PRN=PRN;
    strcpy(nnode->Name,Name);
    printf("Enter the position where you want to insert the data : ");
    scanf("%d",&pos);
    k=len(head);
    if(pos>k+1){
        printf("Data can't be entered at this position");
    }
    else{
        while(curr!=NULL && i<pos){
            i++;
            curr=curr->next;
        }
        nnode->next=curr->next;
        curr->next=nnode;
    }


}

void delpos(struct node *head){
    struct node *prev =(struct node*)malloc(sizeof(struct node));
    struct node *curr =(struct node*)malloc(sizeof(struct node));
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    prev=head;
    int pos,counter=1;
    curr=head->next;
    printf("Enter the position of data to be deleted : ");
    scanf("%d",&pos);
    int k = len(head);
    if (k<pos){
        printf("Data can't be deleted from given position");
        }
    else {
        while(counter<pos && curr!=NULL){
            counter++;
            prev=curr;
            curr=curr->next;
        }
        temp=curr;
        prev->next=curr->next;
        curr->next=NULL;
        free(temp);
    }

}

void sort(struct node *head){
	int i,j,l=len(head);
	for (i=0;i<l-1;i++){
		struct node *prev =(struct node*)malloc(sizeof(struct node));
		struct node *curr=(struct node*)malloc(sizeof(struct node));
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		prev=head;
		curr=head->next;
		for (j=0;j<l-1;j++){
			temp=curr->next;
			if (curr->PRN > temp->PRN){
				prev->next = temp;
				curr->next = temp->next;
				temp->next=curr;
				prev=temp;
			}
			else{
				prev=curr;
				curr=curr->next;
			}
		}
	}
}

void merge(struct node *head1,struct node *head2){
			int flag;
			struct node *curr1 =(struct node*)malloc(sizeof(struct node));
			struct node *curr2=(struct node*)malloc(sizeof(struct node));
			struct node *temp=(struct node*)malloc(sizeof(struct node));
			curr1=head1->next;
			curr2=head2->next;
			if(curr1->PRN < curr2->PRN){
				temp=head1;
				flag=1;
			}
			else{
				temp=head2;
				flag=0;
			}
			while(curr1!=NULL && curr2!=NULL){
				if(curr1->PRN < curr2->PRN){
					temp->next=curr1;
					temp=curr1;
					curr1=curr1->next;
				}
				else{
					temp->next=curr2;
					temp=curr2;
					curr2=curr2->next;
				}
			}
			if(curr1==NULL){
				temp->next=curr2;
			}
			if(curr2==NULL){
							temp->next=curr1;
						}
			if(flag==1){
				printf("Merged Linked list is : \n");
				display(head1);
			}
			else{
				printf("Merged Linked list is : \n");
				display(head2);
			}
}

void reverse(struct node *head){
    struct node *prev=(struct node*)malloc(sizeof(struct node));
    struct node *curr=(struct node*)malloc(sizeof(struct node));
    struct node *future=(struct node*)malloc(sizeof(struct node));
    prev=NULL;
    curr=head->next;
    while(curr!=NULL){
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    head->next=prev;
}

int main(){
struct node *head1 =(struct node *)malloc(sizeof(struct node));
struct node *head2 =(struct node*)malloc(sizeof(struct node));
int a,b,ch,l1=0,l2=0;
    head1->next=NULL;
    head2->next=NULL;
    printf("For First Linked List -\n");
    createnode(head1);
    printf("\n");
    printf("For Second Linked List -\n");
    createnode(head2);
    printf("\nData in the First Linked List is : ");
    display(head1);
    printf("\nData in the Second Linked List is : ");
    display(head2);

do{
    printf("\n-------------------------------------------------------------\n");
    printf("Enter the operation you want to perform on Simply Linked List");
    printf("\n1.Insert\n2.Delete\n3.Length\n4.Sort\n5.Merge\n6.Reverse\n");
    printf("---------------------------------------------------------------\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:do{
        	   printf("In which SLL do you want to insert node?\n1.First\n2.Second\n3.None\n");
        	   scanf("%d",&a);
        	   switch(a){
        	   case 1: insert(head1);
        	   	   	   printf("\nData in the First Linked List after insert operation is : ");
            		   display(head1);
            		   printf("\n");
            		   break;
        	   case 2: insert(head2);
        	   	   	   printf("\nData in the Second Linked List after insert operation is : ");
        	           display(head2);
        	           printf("\n");
        	           break;
        	   case 3: break;
        	   }
        }while(a<3);
        break;

        case 2:do{
     	       printf("In which SLL do you want to delete node?\n1.First\n2.Second\n3.None\n");
     	       scanf("%d",&b);
     	       switch(b){
     	       case 1: delpos(head1);
     	       	   	   printf("\nData in the First Linked List after delete operation is : ");
           		       display(head1);
           		       printf("\n");
         		       break;
     	       case 2: delpos(head1);
     	       	   	   printf("\nData in the Second Linked List after delete operation is : ");
     	               display(head1);
     	               printf("\n");
     	               break;
     	       case 3: break;
     	       }
         }while(b<3);
          break;
        case 3:l1=len(head1);
        	   printf("\nLength of the First Linked List is : %d\n",l1);
        	   l2=len(head2);
        	   printf("\nLength of the Second Linked List is : %d\n",l2);
        	   break;
        case 4:sort(head1);
        	   printf("\nData in the First Linked List after sort operation is : ");
        	   display(head1);
        	   sort(head2);
        	   printf("\nData in the Second Linked List after sort operation is : ");
        	   display(head2);
        	   break;
        case 5:sort(head1);
               sort(head2);
               merge(head1,head2);
               break;

        case 6:reverse(head1);
        	   printf("\nData in the First Linked List after reverse operation is : ");
        	   display(head1);
        	   reverse(head2);
        	   printf("\nData in the Second Linked List after reverse operation is : ");
        	   display(head2);
        	   break;
        default : printf("Enter valid option!");
    }
}while(1);
return 0;
}
