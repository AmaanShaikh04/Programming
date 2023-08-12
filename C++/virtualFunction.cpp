/*Write a program to create a base class Shape having area() as a virtual function. 
Derive a class Circle from Shape and override area() function to demonstrate the use of virtual function.*/
#include <iostream>
#define PI 3.141
using namespace std;
class Shape
{
	private:
	public:
		virtual void area()
		{
			cout << "Experiment 3, Question 3\n";
		}
};
class Circle:public Shape
{
	private:
		
		int r;
	public:
		void area()
		{
			cout << "\nEnter the radius of the circle: ";
			cin >> r;
			cout << "\nArea: " << PI*r*r << "\n";
		}
};
int main()
{
	Circle obj1;
	Shape *ptr=new Shape;	//used to create a pointer object
	ptr->area();
	delete ptr;	//used to destroy pointer object
	ptr=&obj1;
	ptr->area();
	return 0;
}
