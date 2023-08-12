/*Write a program to implement multilevel inheritance. Accept and display
whole data of one student.*/
#include <iostream>
using namespace std;
class student
{
	public:
		int roll;
		char name[30];
		void getdata()
		{
			cout << "Enter roll number: ";
			cin >> roll;
			cout << "Enter name: ";
			cin >> name;
			
		}
};
class test:public student
{
	public:
		int m1,m2,sp;
		void getmarks()
		{
			cout << "Enter marks 1 and marks 2" <<endl;
			cin>>m1>>m2;
			cout<<"Enter sp"<<endl;
			cin>>sp;
		}
};
class result:public test
{
	public:
		int res;
		void getres()
		{
			res=m1+m2+sp;
			cout << "Name: " << name << endl << "Roll no: " << roll <<endl << "Total: " << res <<endl;
		}
};
int main()
{
	result obj;
	obj.getdata();
	obj.getmarks();
	obj.getsp();
	obj.getres();
	return 0;
}
