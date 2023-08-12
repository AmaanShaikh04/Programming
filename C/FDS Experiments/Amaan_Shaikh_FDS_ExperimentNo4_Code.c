

#include<stdio.h>

void
accept (int n, int Marks[20])
{
  int i;
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &Marks[i]);
    }
}

void
display (int n, int Marks[20])
{
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("%d\n", Marks[i]);
    }
}

void
displayf (int n, int Marks[20])
{
  int i;
  for (i = n-1; i>(n-6); i--)
    {
      printf ("%d\n", Marks[i]);
    }
}

void
bucketsort (int A[200], int n)
{
  int bucket[100], i =0, j = 0;
  for (i = 0; i < 100; i++)
    {
      bucket[i] = 0;
    }
  for (i = 0; i < n; i++)
    {
      ++bucket[A[i]];
    }
  for (i = 0, j = 0; i < 100; i++)
    {
      for (; bucket[i] > 0; --bucket[i])
{
  A[j] = i; j++;
}
}
}

  int main ()
  {
    int Marks[20], n;
    printf
      ("Enter the number of students whose percentage are to be entered:  ");
    scanf ("%d", &n);
    printf ("\nEnter the percentage of students:\n");
    accept (n, Marks);
    printf ("\nRecord before sorting :\n");
    display (n, Marks);
    bucketsort (Marks, n);
    printf ("\nRecord after sorting :\n");
    display (n, Marks);
    printf ("\nThe percentages of top 5 students are:\n");
    displayf (n, Marks);
    return 0;
  }
