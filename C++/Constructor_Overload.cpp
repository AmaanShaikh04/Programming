//Write a program to demonstrate constructor overloading.
#include <iostream>
using namespace std;
class SC
{
	public:
		int i;
		SC()
		{
			for(i=1;i<11;i++)
			cout << i;
		}
		SC(int a)
		{
			for(i=1;i<11;i++)
			cout << i*a << endl;
		}
		SC(float f)
		{
			for(i=1;i<11;i++)
			cout << i*f << endl;
		}
};
int main(int argc, char const *argv[])
{
	int a,x;
	float y;
	cout << "Press 1 for printing 1-10.\n";
	cout << "Press 2 for knowing 10 multiples of an integer.\n";
	cout << "Press 3 for knowing 10 multiples of an floating value.\n";
	cin >> a;
	switch(a)
	{
		case 1: 
			SC obj();
			break;
		case 2: 
			cout << "Enter Integer.\n";
			cin >> x;
			SC obj1(x);
			break;
		case 3:
			cout << "Enter Floating value.\n";
			cin >> y;
			SC obj2(y);
			break;
		default:
			cout << "Wrong Choice.\n";
	}
	return 0;	
}
