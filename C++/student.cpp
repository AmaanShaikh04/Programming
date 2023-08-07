/*
	Filename: student.cpp
	Description: Display the input taken of a student's name, roll number, and class. 
*/

#include <iostream>

using namespace std;

class student
{
public:
	int rn;
	char name[20], cls[10];
	
	void ip()
	{
		cout << "Enter the name , roll number and class of a student: ";
		cin >> name;
		cin >> rn;
		cin >> cls;	
	}
	
	void op()
	{
		cout << "\nName: " << name << "\nRoll number: " << rn << "\nClass: " << cls << "\n";
	}
};

int main()
{
	student s1;
	
	s1.ip();
	s1.op();
}
//EOF
