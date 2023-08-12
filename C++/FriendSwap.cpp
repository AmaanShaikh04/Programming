#include<iostream>
using namespace std;
class Swap
{
    public:
    	int a,b,temp;
		friend void swap(Swap &t);
    	void input()
		{
        	cout << "Enter two numbers:\n";
        	cin >> a >> b;
        	cout << "Before swap 'a' is:" << a << endl;
    		cout << "Before swap 'b' is:" << b << "\n\n";
    	}
    	void display()
		{
        	cout << "After swap 'a' is:" << a << endl;
        	cout << "After swap 'b' is:" << b << endl;
    	}
};
void swap(Swap &t)
{
    t.temp=t.a;
    t.a=t.b;
    t.b=t.temp;
}
int main()
{
    Swap t;
    t.input();
    swap(t);
    t.display();
    return 0;
}
