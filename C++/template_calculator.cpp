/*	*Write  a program to create a class template having name calculator. 
	*The calculator should perform operations on various types of data. 
	*The class should contain public member functions to calculate the addition, subtraction, multiplication and division 
	*of the numbers which return the value of data type defined by the user and a function displayResult() to 
	*display the final output to the screen.
*/
#include <iostream>
using namespace std;
template <class x> class calculator
{
	private:
		x num1,num2;
	public:
		calculator(x n1,x n2)
		{
			num1=n1;
			num2=n2;
		}
		void display()
		{
			cout << "Addition: " << add() << endl;
			cout << "Subtraction: " << sub() << endl;
			cout << "Multiplication: " << mul() << endl;
			cout << "Division: " << div() << endl;
		}
		x add()
		{
			return num1+num2;
		}
		x sub()
		{
			return num1-num2;
		}
		x mul()
		{
			return num1*num2;
		}
		x div()
		{
			return num1/num2;
		}
};
int main()
{
	int a,b;
	cout << "Enter two integer values\n";
	cin >> a >> b;
	calculator <int> c1(a,b);
	c1.display();
	double x,y;
	cout << "\nEnter two doublle values\n";
	cin >> x >> y;
	calculator <double> c2(x,y);
	c2.display();
	return 0;
}
