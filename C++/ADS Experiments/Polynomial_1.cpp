#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coef;
    int exp;
    struct poly* next;
};


void create(struct poly*head)
{
    struct poly* temp = head;
    char ch;
    do{   
        struct poly* curr = (struct poly*)malloc(sizeof(struct poly));
        printf("Enter the coefficient and exponent of the polynomial equation : \n");
        scanf("%d %d", &curr->coef,&curr->exp);
        curr->next = head;
        temp->next = curr;
        temp=curr;
        printf("Do you want to another node?\n");
        printf("1.Y\t2.N\n");
        scanf(" %c", &ch);
    }while(ch=='y');
}

void display(struct poly* head)
{
	struct poly* curr = head->next;
	while(curr!=head)
	{
	    if(curr->exp > 1 && curr->coef != 0)
		{
	        if(curr->next!=head && curr->next->coef > 0)
	            printf("%dx^%d+",curr->coef,curr->exp);
	        else
	            printf("%dx^%d",curr->coef,curr->exp);
	        curr=curr->next;
	    } 
	    else if(curr->exp==1 && curr->coef != 0)
		{
	        if(curr->next!=head && curr->next->coef > 0 )
	            printf("%dx+",curr->coef);
	        else
	            printf("%dx",curr->coef);
	        curr=curr->next;
	    }
	    else if(curr->exp==0 )
		{
	        if(curr->coef != 0)
			{
	            printf("%d",curr->coef);
	            curr=curr->next;
	        }
	        else
	            curr=curr->next;
		}
	}
}

void addition(struct poly* head1,struct poly* head2)
{
    struct poly* head3=(struct poly*)malloc(sizeof(struct poly));
    struct poly* temp=(struct poly*)malloc(sizeof(struct poly));
    head3->next=head3;
    struct poly* t3=head3;
    struct poly* t2=head2->next;
    struct poly* t1=head1->next;
    while(t1->exp!=-1 || t2->exp!=-1)
	{
        struct poly* temp=(struct poly*)malloc(sizeof(struct poly));
        if(t1->exp==t2->exp)
		{
            temp->coef=t1->coef+t2->coef;
            temp->exp=t1->exp;
            t3->next=temp;
            temp->next=head3;
            t3=t3->next;
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->exp < t2->exp)
		{
                temp->coef=t2->coef;
                temp->exp=t2->exp;
                t3->next=temp;
                temp->next=head3;
                t3=t3->next;
                t2=t2->next;
            }
        else{
                temp->coef=t1->coef;
                temp->exp=t1->exp;
                t3->next=temp;
                temp->next=head3;
                t3=t3->next;
                t1=t1->next;
        }
    }
    printf("Addition of the two polynomials is -\n");
    display(head3);
}

int main()
{
    struct poly* head1=(struct poly*)malloc(sizeof(struct poly));
    struct poly* head2=(struct poly*)malloc(sizeof(struct poly));
    head1->next=head1;
    head2->next=head2;
    head1->exp = -1;
    head2-> exp = -1;
    create(head1);
    printf("First polynomial -\n");
    display(head1);
    printf("\n\n");
    create(head2);
    printf("Second polynomial -\n");
    display(head2);
    printf("\n\n");
    addition(head1,head2);

    return 0;
}
