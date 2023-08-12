#include<iostream>
using namespace std;
class Test
{
private: static int x;
public: static void fun()
{
cout<<endl<<x;
x++;
}
};
int Test :: x =20;
int main()
{
Test x,y;
x.fun();
x.fun();
y.fun();
}
