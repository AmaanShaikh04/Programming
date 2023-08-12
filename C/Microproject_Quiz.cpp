#include <stdio.h>
int main()
{
	int s=0;
	int ans;
	printf("Welcome to the C quiz\nThe quiz has 5 very basic questions on the C Programming Language. You get +3 for each correct answer & -1 for each wrong/invalid answer.\n");
	printf("\nQ1) Why is it called 'C' & not 'D'?\n");
	printf("[1]C stands for code\t[2]The inventor’s name started with a C\n[3]It developed after a language called 'B'\t[4]Why should I care?\n");
	scanf("%d", &ans);
	if(ans==3)
	{
		printf("That's Correct!\n");
		s=s+3;
	}
	else
	{
		printf("Wrong Answer\n");
		printf("Correct answer is [3]It developed after a language called 'B'");
		s--;
	}	
	printf("\nQ2) It was developed at?\n");
	printf("[1]IBM\t[2]Bell Labs\n[3]MIT\t[4]Microsoft\n");
	scanf("%d", &ans);
	if(ans==2)
	{
		printf("That's Correct!\n");
		s=s+3;
	}
	else
	{
		printf("Wrong Answer\n");
		printf("Correct answer is [2]Bell Labs");
		s--;
	}
	printf("\nQ3) Which of these is not a C keyword as per ANSI C?\n");
	printf("[1]extern\t[2]volatile\n[3]enter\t[4]break\n");
	scanf("%d", &ans);
	if(ans==3)
	{
		printf("That's Correct!\n");
		s=s+3;
	}
	else
	{
		printf("Wrong Answer\n");
		printf("Correct answer is [3]enter");
		s--;
	}
	printf("\nQ4) What is ANSI?\n");
	printf("[1]Area of Natural and Scientific Interest\t[2]American National Standards Institute\n[3]American National Standardization Institute\t[4]American National Society Of Intellectuals\n");
	scanf("%d", &ans);
	if(ans==2)
	{
		printf("That's Correct!\n");
		s=s+3;
	}
	else
	{
		printf("Wrong Answer\n");
		printf("Correct answer is [2]American National Standards Institute");
		s--;
	}
	printf("\nQ5) Which of these concepts is NOT supported by C ?\n");
	printf("[1]Pointers\t[2]Functions\n[3]Strings\t[4]Namespaces\n");
	scanf("%d", &ans);
	if(ans==4)
	{
		printf("That's Correct!\n");
		s=s+3;
	}
	else
	{
		printf("Wrong Answer\n");
		printf("Correct answer is [4]Namespaces");
		s--;
	}
	printf("\nThank You for taking the Quiz.\n Your Total Score is %d out of 15", s);
	return 0;
}
