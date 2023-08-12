//Write a program to handle "Divide by zero"  exception if the denominator is zero.
#include <iostream> 
using namespace std;
int main()
{
	int n,d;
	cout<<"Enter numerator:\n";
	cin>>n;
	cout<<"Enter denominator:\n";
	cin>>d;
	try
	{
		if(d==0)
		{
			throw d;
		}
		else
		{
			cout<<(n/d);
		}
	}
	catch(int)
	{
		cout<<"Denominator cannt be zero !";
	}
	return 0;
}
