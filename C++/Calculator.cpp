//write a program to declare a class Calculator, accept 2 integers from user in get method and perform different operations on the integers in another method. Create object and pointer and call all methods of class using pointer statements
#include <iostream>
#include <math.h>
using namespace std;
class Calculator
{
	private:
		int a,b;
		int sum;
		int diff;
		int prod;
		double quo;
	public:
		void get(void);
		void cal(void);
}obj;
void Calculator::get(void)
{
	cout << "Enter 2 integers";
	cin >> a;
	cin >> b;
}
void Calculator::cal(void)
{
	sum=a+b;
	diff=a-b;
	prod=a*b;
	quo=a/b;
	int a2,b2;
	a2=a*a;
	b2=b*b;
	cout << "Sum= " << sum;
	cout << "Difference= " << diff;
	cout << "Product= " << prod;
	cout << "Quotient= " << quo;
	cout << "a square= " << a2;
	cout << "b square= " << b2;
}
int main()
{
	Calculator obj;
	Calculator *p;
	p->get();
	p->cal();
	return 0;
}
