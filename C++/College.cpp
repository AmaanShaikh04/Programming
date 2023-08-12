/*Define a class ‘College’ members variables as roll_no,name,course. WAP using constructor with default value as “Computer Engineering”
for course. Accept this data for two objects of class and display the data*/
#include <iostream>
#include <string>
using namespace std;
class College
{
private:
	int roll_no;
	string name;
	string course = "Computer Engineering";
public:
	College(const College &obj)
	{
		cout << "\tDefault Course set to " << obj.course << "\n\n";
	}
	void getValues()
	{
		char ch;
		cout << "Enter name of Student: ";
		getline(cin, name);
		cout << "Enter Roll number of Student: ";
		cin >> roll_no;
		cout << "Do you want to change your course?(Y/N)\nYour Choice: ";
		cin >> ch;
		if((ch == 'Y') || (ch == 'y'))
		{
			cout << "Enter your Course: ";
			getline(cin, course);
		}
	}
	void putValues()
	{
		cout << "\nName: " << name << endl;
		cout << "Roll Number: " << roll_no << endl;
		cout << "Course: " << course << endl;
	}
};
int main(int argc, char const *argv[])
{
	College obj(obj);
	obj.getValues();
	obj.putValues();
	return 0;
}
