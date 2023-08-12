

#include<stdio.h>
struct student
{
  int rollno;
  char name[10];
  int marks;
};

void accept (struct student s[10], int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%d%s%d", &s[i].rollno, &s[i].name, &s[i].marks);
    }
}

void display (struct student s[10], int n)
{
  int i;
  printf ("Roll No\t  Name\tMarks\n");
  for (i = 0; i < n; i++)
    {
      printf (" %d\t  %s\t %d\n", s[i].rollno, s[i].name, s[i].marks);
    }
}

void linear (struct student s[10], int n, int key)
{
  int i,flag;
  printf ("\nEnter the roll number you want to search:\n");
  scanf ("%d", &key);
  for (i = 0; i < n; i++)
    {
      if (s[i].rollno == key)
	{
	  printf ("Target key found!\n");
	  printf ("Roll no\t  Name\tMarks\n");
	  printf ("  %d \t   %s \t %d\n", s[i].rollno, s[i].name, s[i].marks);
	  flag=1;
	}
    }
	if(flag!=1){
	   printf ("Target key not found!\n"); 
	}
}

int binary (struct student s[10], int low, int high, int key, int n)
{
  int mid;
  low = 0;
  high = n - 1;
  printf ("Enter the roll number you want to search:\n");
  scanf ("%d", &key);
  while (low <= high)
    {
      mid = (low + high) / 2;
      if (s[mid].rollno == key)
	{
	  return mid;
	}
      else if (key < s[mid].rollno){
	   high = mid - 1;
	  }
      else{
	  low = mid + 1;
	  }
    }
     return -1;
    
}

int recursive_binary (struct student s[10], int low, int high, int key, int n)
{
  int mid;
  low = 0;
  high = n - 1;
  while (low <= high)
    {
      mid = (low + high) / 2;
      if (s[mid].rollno == key){
		return mid;
	  }
      else if (key < s[mid].rollno){
		return recursive_binary (s, mid + 1, high, key, n);
	  }
      else{
		return recursive_binary (s, low, mid - 1, key, n);
    }
  return -1;
}
}

void selectionsort(struct student s[10], int n){
	int i,j,minpos;
	struct student temp;

	for(i=0;i<(n-1);i++)
	{
		minpos=i;
		for(j=(i+1);j<n;j++)
		{
			if (s[j].rollno < s[minpos].rollno)
			{
			 minpos=j;
			}
		}
		  if(minpos!=i)
		  {
			  temp= s[i];
			  s[i] = s[minpos];
			  s[minpos] =temp;

		  }
	}
     display(s,n);
}

void shellsort(struct student s[10], int n){
    int gap=n/2,swapped,i;
    struct student temp;
    do{
        do{
            swapped=0;
            for(i=0;i<n-gap;i++){
                if(s[i].rollno>s[i+gap].rollno){
                    temp= s[i];
			        s[i] = s[i+gap];
		        	s[i+gap] =temp;
		        	swapped++;
                }
            }
        }while(swapped==1);
    }while((gap=gap/2)>=1);
    display(s,n);
}

void insertionsort(struct student s[10], int n){
	struct student temp;
	int i,j;
	for(i=0;i<n;i++){
		temp= s[i];
		j = i-1;
		while(j>=0 && s[j].rollno > temp.rollno){
			s[j+1]=s[j];
			j=j-1;
		}
		 s[j+1]=temp;
	}
	 display(s,n);
}

int main ()
{
  int n, low, high, key, x, y, mid, choice, ch,c;
  struct student s[10];
  struct student temp[10];
  printf ("Enter the number of students: \n");
  scanf ("%d", &n);
  printf ("\nEnter the Roll No, Names and Marks respectively\n");
  accept (s, n);
  printf ("\nThe data you entered is:\n");
  display (s, n);
  do
    {
      printf ("\nEnter the operation you want to perform:\n");
      printf ("1.Searching\n2.Sorting\n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  do
	    {
	      printf ("\nDifferent searching operations -\n");
	      printf
		("1.Linear Search\n2.Binary Search(Non-recursive)\n3.Binary Search(Recursive)\n4.Exit");
	      printf("\nEnter the type of search you want to execute :");
	      scanf("%d", &choice);
	      switch(choice)
		{
		case 1:
		  linear (s, n, key);
		  break;
		case 2:
		  x = binary (s, low, high, key, n);
		  if (x > 0)
		    {
		      printf ("Target key has been found!\n");
		      printf ("Roll no\t  Name\tMarks\n");
		      printf ("  %d \t  %s \t  %d\n", s[x].rollno, s[x].name,
			      s[x].marks);
		    }
		  else
		    printf ("Target key has not been found!\n");
		  break;
		case 3:
		  printf ("\nEnter the roll number you want to search:\n");
		  scanf ("%d", &key);
		  y = recursive_binary (s, low, high, key, n);
		  if (y >= 0)
		    {
		      printf ("Target key has been found!\n");
		      printf ("Roll no\t  Name\tMarks\n");
		      printf ("  %d \t  %s \t  %d\n", s[y].rollno, s[y].name,
			      s[y].marks);
		    }
		  else
		    printf ("Target key has not been found!\n");
		  break;
		  
		}
	    }while (choice<4);
	    break;

	case 2:  do
	          {        
	         printf ("\nDifferent sorting operations -\n");
             printf("1.Selection Sorting\n2.Shell Sorting\n3.Insertion Sorting\n4.Exit\n");
             printf ("\nEnter the type of sorting you want to execute :");
             scanf ("%d", &c);
             switch (c)
             {
             case 1 : selectionsort(s,n);
                      break;
             case 2 : shellsort(s,n);
                      break;
             case 3 : insertionsort(s,n);
                      break;
             }
             }while(c<4);
	}
    }while (1);
      return 0;
}
