/*Write a program to implement hierarchical inheritance. Assume
suitable data.*/
#include <iostream>
using namespace std;
class triangle
{
	public:
		int b,h;
		void get_tri()
		{
			cout << "Enter height and base:\n";
			cin >> h >>b;
		}
};
class rectangle
{
	public:
		int br,l;
		void get_rect()
		{
			cout << "Enter length and breadth:\n";
			cin >> l >> br;
		}
};
class shape:public triangle,public rectangle
{
	public:
		float a;
		void areatri()
		{
			a=0.5*b*h;
			cout << "Area of triangle= " << a << endl;
		}
		void arearec()
		{
			a=br*l;
			cout << "Area of rectangle= " << a << endl; 
		}
};
int main()
{
	shape obj;
	obj.get_tri();
	obj.get_rect();
	obj.areatri();
	obj.arearec();
	return 0;
}
