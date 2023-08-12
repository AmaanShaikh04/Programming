#include <iostream>
using namespace std;
class demo
{
	public:
		static int count;
		demo()
		{
			count++;
		}
		void display()
		{
			cout << "Hello World" << endl;
		}
};int demo::count;
int main()
{
	demo obj1;
	demo obj2;
	demo obj3;
	demo obj4;
	obj1.display();
	obj2.display();
	obj3.display();
	obj4.display();
	cout << "Number of objects= " << demo::count;
	return 0;
}
