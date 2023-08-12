/*Write a program to implement single inheritance. Assume suitable
data.(Note: Can refer following problem statement or any other suitable
data)
Write a program to implement single inheritance by declaring a base class
as employee having data members emp_id and name. from this base class
derive a child class fitness having data members as height and weight
using public visibility mode. Accept and display data for one employee.*/
#include <iostream>
using namespace std;
class base
{
	public:
		int id;
		char name[30];
		void employee()
		{
			cout << "Enter Employee name: ";
			cin >> name;
			cout << "Enter id number: ";
			cin >> id;
		}
};
class derived:public base
{
	public:
		int height,weight;
		void fitness()
		{
			cout << "Enter height in inches: ";
			cin >> height;
			cout << "Enter weight in kgs: ";
			cin >> weight;
		}
};
int main()
{
	derived obj1;
	obj1.employee();
	obj1.fitness();
	return 0;
}
