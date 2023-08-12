//Write a program to demonstrate constructor overloading.
#include <iostream>
using namespace std;
class Dim
{
	private:
    	double length;
    	double breadth;
	public:
		Dim() 
		{
	        length = 6.9;
	        breadth = 4.2;
	    }
		Dim(double l, double b) 
		{
	        length = l;
	        breadth = b;
	    }
	    Dim(double len) 
		{
	        length = len;
	        breadth = 7.2;
	    }
	    double calculateArea() 
		{
	        return length*breadth;
	    }
};
int main() 
{
    Dim obj1, obj2(8.2,6.6), obj3(8.2);
    cout << "When no argument is passed: " << endl;
    cout << "Area of room = " << obj1.calculateArea() << endl;
    cout << "\nWhen (8.2, 6.6) is passed." << endl;
    cout << "Area of room = " << obj2.calculateArea() << endl;
    cout << "\nWhen breadth is fixed to 7.2 and (8.2) is passed:" << endl;
    cout << "Area of room = " << obj3.calculateArea() << endl;
    return 0;
}
