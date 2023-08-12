//Write a program to overload decrement operator (--) operator to decrement the value of an object.
#include <iostream>
using namespace std;
class Ovr
{
	private:
		int a=5;
  	public:
	    Ovr* operator -- ()
	    {
	        //Ovr tp;	
	        a=--a;
	        return this;
	    }
	    Ovr* operator -- (int)
	    {
	        //Ovr tp;
	        a=a--;
	        return this;
	    }
	    void print()
	    {
			cout << "Value of a = "<< a << "\n"; 
		}
};
int main()
{
    Ovr ob;
    ob.print(); 
    --ob;
    ob.print();
    ob--;
    ob.print();
	return 0;
}
