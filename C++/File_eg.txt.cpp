//Write ‘C’ program to demonstrate various file operations.
# include <stdio.h>
# include <string.h>
int main()
{
	FILE *ptr;
	char str[50]="This is the file of Amaan Shaikh SYCO";
	ptr=fopen("F:\\College Stuff\\Submissions\\DSF\\eg.txt","w");
	if(ptr==NULL)
	{
		printf("eg.txt file failed to open.");
	}
	else
	{
		printf("The file is now opened.\n");
		if(strlen(str)>0)
		{
			fputs(str, ptr);
			fputs("\n", ptr);
		}
		fclose(ptr);
		printf("The file is now closed.");
	}
	return 0;
}
