#include <iostream>
using namespace std;
#define MAX 10
class StatDemo
{
	public:
		int data1; 
		static int data2; 
		void getData(void)
		{
			cout << "Enter values: ";
			cin >> data1 >> data2;
		}
		void putData(void)
		{
			data1++;
			data2++;
			cout << "Data 1: " << data1 << "\t";
			cout << "Data 2: " << data2 << "\n";
		}
};
int StatDemo::data2=0;
int main()
{
	StatDemo obj1[5];
	int i;
	for(i=0;i<5;i++)
	obj1[i].getData();
	for(i=0;i<5;i++)
	obj1[i].putData();
	return 0;
}
