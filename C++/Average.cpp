#include <iostream>
using namespace std;
#define MAX 10
class result2;
class result1
{
    public:
    	int x;
        void getDetails(int a)
        {
        	x=a;
        	cout << "Value of x: " << a << endl;
		}
};
class result2
{
    public:
    	int y;
        void getDetails(int a)
        {
        	y=a;
        	cout << "Value of y: " << a << endl;
		}
};
int main()
{
    result1 obj1;
    result2 obj2;
    obj1.getDetails(100);
    obj2.getDetails(250);
    int avg=(obj1.x+obj2.y)/2;
    cout << "The average is: " << avg << endl; 
    return 0;
}
