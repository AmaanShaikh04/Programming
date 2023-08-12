#include <iostream>
using namespace std;
#define MAX 10
class Operations
{
	private:
		int sum,diff,prod,quo;
	public:
		int Add(int a,int b);
		int Sub(int a,int b);
		int Mul(int a,int b);
		int Div(int a,int b);
};
int Operations::Add(int a,int b)
{
	sum=a+b;
	return sum;
}
int Operations::Sub(int a,int b)
{
	diff=a-b;
	return diff;
}
int Operations::Mul(int a,int b)
{
	prod=a*b;
	return prod;
}
int Operations::Div(int a,int b)
{
	quo=a/b;
	return quo;
}
int main()
{
	Operations obj;
	int a,b;
	cout << "Enter 2 numbers\n";
	cin >> a >> b;
	int sum=obj.Add(a,b);
	int diff=obj.Sub(a,b);
	int prod=obj.Mul(a,b);
	int quo=obj.Div(a,b);
	cout << "Sum:"<<sum<< "\n";
	cout << "Difference:"<<diff<< "\n";
	cout << "Product:"<<prod<< "\n";
	cout << "Quotient:"<<quo<< "\n";
	return 0;
}
