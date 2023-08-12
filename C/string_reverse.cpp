/*
	WOC to reverse a string using recursion without using strrev() function
	Author: Aaditya Arun
	Branch: TYME
*/
#include <stdio.h>

//Function: int main()
//Description: start of the main block
int main()
{
    char s1[100],t;
    int i,j = -1;
    printf("Enter string:\n");
    gets(s1);				//accepting the string
	i = 0;
    
	while(s1[++j]!='\0');	//getting the size of the string
    	j--;
	
	while(i < j)			//reversing
	{
		t = s1[i];
		s1[i] = s1[j];
		s1[j] = t;
		i++;
		j--;
    }
    
    printf("Reverse of a input string is: %s", s1);
    return 0;
}
//end of int main()
