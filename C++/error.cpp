#include <iostream>
using namespace std;
class A
{ public:
int a,b,c;
A()
{
a = 9; b=7; c= a+b;
}
}obj;
int main()
{
cout << "a = " << obj.a << endl;
return 0;
}
