//write a program to calculate the area of circle, rectangle and triangle using function overloading
#include <iostream>
using namespace std;
class overload
{
	private:
	public:
		double ovr(int r)	//for circle
		{
			double area=3.14*r*r;
			return area;
		}
		double ovr(int l,int b)	//for rectangle
		{
			double area=l*b;
			return area;
		}
		double ovr(double b,double h)	//for triangle
		{
			double area=0.5*b*h;
			return area;
		}
};
int main()
{
	overload obj;
	int ch,r,l,b;
	double area,B,h;
	cout << "Enter 1 for circle\n"
		 << "Enter 2 for rectangle\n"
		 << "Enter 3 for triangle\n";
	cin >> ch;		//accepting choice
	switch(ch)		// calling the function respective of the choice
	{
		case 1:
			cout << "Enter Radius of circle:\n";
			cin >> r;
			area=obj.ovr(r);
			break;
		case 2:
			cout << "Enter Length and breadth of rectangle:\n";
			cin >> l >> b;
			area=obj.ovr(l,b);
			break;
		case 3:
			cout << "Enter Base and Height of Triangle:\n";
			cin >> B >> h;
			area=obj.ovr(B,h);
			break;
		default:
			cout << "/t/t/t/tWrong Choice\n";	
	}
	cout << "Area = " << area << endl;
	return 0;
}		//end of main
