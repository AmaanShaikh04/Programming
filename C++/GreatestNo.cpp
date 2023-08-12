#include <iostream>
using namespace std;
#define MAX 10
class b;
class a
{
    public:
    	int x;
        void getDetails(int o)
        {
        	x=o;
        	cout << "Value of x: " << o << endl;
		}
		friend int max(a,b);
};
class b
{
    public:
    	int y;
        void getDetails(int o)
        {
        	y=o;
        	cout << "Value of y: " << o << endl;
		}
		friend int max(a,b);
};
int max(a o1,b o2)
{
	if(o1.x>o2.y)
	return o1.x;
	else
	return o2.y;
}
int main()
{
    a obj1;
    b obj2;
    obj1.getDetails(19);
    obj2.getDetails(25);
    cout << "The Greatest number is: " << max(obj1,obj2) << endl; 
    return 0;
}
