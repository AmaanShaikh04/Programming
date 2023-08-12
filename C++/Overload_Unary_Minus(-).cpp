//Write a program to overload unary (-) operator to negate the value of object
#include<iostream>
using namespace std;
class A
{
	private:
    	int num;
	public:
    	void getData(int x)
		{
        num=x;
    	}
        void putData(void)
        {
            cout << "Value of num is: " << num;
        }
        void operator - (void)
        {
            num=-num;
        }
};
int main()
{
    A obj;
    obj.getData(250);
    -obj;
    obj.putData();
    cout << endl;
    return 0;     
}
