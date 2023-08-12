#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// importing required packages

// creating a node structure
struct node
{
	// social security number, name, department, designation
	char ssn[20], name[20], dept[10], desg[10];
	int sal;			// salary
	long int phno;		// phone number
	struct node *rlink;	
	struct node *llink;	
};
typedef struct node* NODE;
NODE head=NULL; 		// declaring a pointer
int count=0;

// function name: NODE createEmployeeNode()
// description: accepts and stores the data required
NODE createEmployeeNode()
{

	NODE employee;
	employee=(NODE)malloc(sizeof(struct node));	// allocate memory to employee

	if(employee==NULL)
	{
		printf("Out of Memory\n");
		exit(0);
	}
	employee->rlink=NULL;
	employee->llink=NULL;

	char ssn[20], name[20], dept[10], desg[10];
	int sal;
	long int phno;

	printf("Enter SSN: ");
	scanf("%s", ssn);
	printf("Enter Name: ");
	scanf("%s", name);
	printf("Enter Department: ");
	scanf("%s", dept);
	printf("Enter Designation: ");
	scanf("%s",desg);
	printf("Enter Salary: ");
	scanf("%d", &sal);
	printf("Enter Phone Number: ");
	scanf("%ld", &phno);
	// accepting data

	strcpy(employee->ssn, ssn);
	strcpy(employee->name, name);
	strcpy(employee->dept, dept);
	strcpy(employee->desg, desg);
	employee->sal=sal;
	employee->phno=phno;
	// copying the data into employee node
	
	count++;
	return employee;
}
// end of NODE createEmployeeNode()

// function name: NODE insert_front() 
// description: insert at beginning
NODE insert_front()
{
	NODE temp;
	temp=createEmployeeNode();

	if(head==NULL)		// checks is the list is empty
	{
		return temp;
	}

	temp->rlink=head;
	head->llink=temp;

	return temp;
}
// end of NODE insert_front()

// function name: NODE insert_end()
// description: insert at end
NODE insert_end()
{
	NODE cur, temp;
	temp=createEmployeeNode();

	if(head==NULL)		// checks is the list is empty
	{
		return temp;
	}
	cur=head;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	cur->rlink=temp;
	temp->llink=cur;

	temp->rlink=NULL;

	return head;

}
// end of NODE insert_end()

// function name: NODE del_front()
// description: delete from beginning
NODE del_front()
{
	NODE temp;

	if(head==NULL)			// checks if the list is empty
	{
		printf("List is empty!\n");
		return NULL;
	}

	if(head->rlink==NULL)
	{
		printf("The employee record with ssn number %s has been deleted\n", head->ssn );
		free(head);
		count--;
		return NULL;
	}

	temp=head;
	temp->rlink=NULL;
	head->llink=NULL;
	printf("The employee record with ssn number %s has been deleted\n", temp->ssn );
	free(temp);
	count--;

	return head;

}
// end of NODE del_front()

// function name: NODE del_end
// description: delete from end
NODE del_end()
{
	NODE prev, cur;
	

	if(head==NULL)		// checks is the list is empty
	{
		printf("List is empty\n");
		return NULL;
	}

	if(head->rlink==NULL)
	{
		printf("The employee record with ssn number %s has been deleted\n", head->ssn );
		free(head);
		count--;
		return NULL;
	}

	prev=NULL;
	cur=head;

	while(cur->rlink!=NULL)
	{
		prev=cur;
		cur=cur->rlink;
	}

	cur->llink=NULL;
	printf("\nThe employee node with ssn %s is deleted\n", cur->ssn);
	free(cur);

	prev->rlink=NULL;
	count--;
	return head;

}
//end of NODE del_end()

// funtion name: void display()
// description: prints list 
void display()
{
	NODE cur;
	cur=head;

	if(cur==NULL)		// checks is the list is empty
	{
		printf("The list is empty\n");
	}
	else
	{

	printf("\nThe contents of the list are\n");
	while(cur!=NULL)
	{
		printf("\nSSN: %s\nName: %s\nDepartment: %s\nDesignation: %s\nSalary: %d\nPhone: %ld \n",cur->ssn, cur->name, cur->dept, cur->desg, cur->sal, cur->phno);
		cur=cur->rlink;
	}
	printf("\nThe number of employees: %d",count);
	printf("\n\n");
	}
}
// end of void display()

// main function
int main()
{
	int ch,i,n;
	while(1)
	{
		printf("\t---Menu---\n");
		printf("1. Create DLL of employee\n");
		printf("2. Display\n");
		printf("3. Insert at Front\n");
		printf("4. Insert at End\n");
		printf("5. Delete at front\n");
		printf("6. Delete at end\n");
		printf("7. Exit\n");

		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter the number of employees!\n");
					scanf("%d",&n);
					for(i=0; i<n; i++)
						head=insert_end();
					break;

			case 2: display();
					break;
			case 3: head=insert_front();
					break;
			case 4: head=insert_end();
					break;
			case 5: head=del_front();
					break;
			case 6: head=del_end();
					break;
			case 7: exit(0);
					break;
			default: printf("Invalid choice\n");
					break;

		}
	}
	return 0;
}
//end of main
