

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define maxsize 20
char stack[maxsize];
int top = -1;
char s[30][30];

int
isfull ()
{
  if (top == maxsize - 1)
    return 1;
  else
    return 0;
}

int
isempty ()
{
  if (top == -1)
    return 1;
  else
    return 0;
}

void
push (char str[maxsize])
{
  if (isfull ())
    {
      printf ("\n Stack is full !");
    }
  else
    {
      strcpy (s[++top], str);
    }
}

void
pop (char str[20])
{
  if (isempty ())
    {
      printf ("\n Stack is empty !");
    }
  else
    {
      strcpy (str, s[top]);
      top--;
    }
}

void
postinfix (char post[maxsize])
{
  char s1[maxsize], s2[maxsize], s3[maxsize], inf[maxsize];
  for (int i = 0; post[i] != '\0'; i++)
    {
      s1[0] = post[i];
      s1[1] = '\0';
      if (isalpha (post[i]) != 0)
	push (s1);
      else
	{
	  pop (s2);
	  pop (s3);
	  strcpy (inf, "(");
	  strcat (inf, s3);
	  strcat (inf, s1);
	  strcat (inf, s2);
	  strcat (inf, ")");
	  push (inf);
	}
    }
  pop (inf);
  printf ("\n The infix expression is :");
  printf ("\n%s", inf);
}

void
postprefix (char post[maxsize])
{
  char s1[maxsize], s2[maxsize], s3[maxsize], pre[maxsize];
  for (int i = 0; post[i] != '\0'; i++)
    {
      s1[0] = post[i];
      s1[1] = '\0';
      if (isalpha (post[i]) != 0)
	push (s1);
      else
	{
	  pop (s2);
	  pop (s3);
	  strcpy (pre,s1);
	  strcat (pre,s3);
	  strcat (pre,s2);
	  push (pre);
	}
    }
  pop (pre);
  printf ("\n The Prefix expression is :");
  printf ("\n%s", pre);
}

void main ()
{
  char post[30];
  printf ("Enter the postfix string :");
  gets(post);
  postinfix (post);
  postprefix(post);

}
