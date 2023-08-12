/*Write a program to open "student.txt" file to write the data of 10
students. The file should contain RollNo, Name and Percentage of
each student.*/
#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	char n[50];
	int roll_no,i,no;
	double perc;
	cout << "Enter number of students: ";
	cin >> no;
	FILE *fptr;
	fptr=(fopen("F:\\College Stuff\\Submissions\\OOP-II\\student.txt","w"));
	if(fptr==NULL) 
	{
		cout << "Error!";
	}
	for(i=0;i<no;++i)
	{
		cout << "For student " << i+1 << endl;
		cout << "Enter name: ";
		cin >> n;
		cout << "Enter Roll No: ";
		cin >> roll_no;
		cout << "Enter Percentage: ";
		cin >> perc;
		fprintf(fptr,"\nName: %s \nRoll No=%d \nPercentage= %lf",n,roll_no,perc);
	}
	fclose(fptr);
	return 0;
}
