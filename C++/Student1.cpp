#include <iostream>
using namespace std;
class student
{
	public:
		char name[20];
		int per;
		student()
		{
			cout << "Enter name and percentage: " << endl;
			cin >> name >> per;
		}
		void display()
		{
			cout << "Name: " << name << endl;
			cout << "Percentage: " << per << endl;
		}
};
int main()
{
	student obj1;
	obj1.display();
	return 0;
}
