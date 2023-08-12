#include <iostream>
using namespace std;
#define MAX 10
class swapp
{
    public:
    	int temp,a,b;
        void abc()
        {
        	cout << "Enter values of a and b: " << endl;
        	cin >> a >> b;
		}
		void bf()
		{
			cout << "Value of a before swapping: " << a << endl;
			cout << "Value of b before swapping: " << b << endl;
		}
		friend void Swap(swapp);
};
void Swap(swapp o1)
{
	o1.temp=o1.a;
	o1.a=o1.b;
	o1.b=o1.temp;
	cout << "Value of a after swapping: " << o1.a << endl;
	cout << "Value of b after swapping: " << o1.b << endl;
}
int main()
{
    swapp obj1;
	obj1.abc();
	obj1.bf();
	Swap(obj1); 
    return 0;
}
