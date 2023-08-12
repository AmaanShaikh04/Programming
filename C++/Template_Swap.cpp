//Write a program to swap data using function templates.
#include<iostream>
using namespace std;
template <class T>
void Swap(T &x,T &y)
{
    T temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a,b;
    cout << "Enter two numbers:\n";
    cin >> a >> b;
    cout << "Before Function Templates:\n";
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    Swap(a,b);
    cout << "\nAfter Function Templates:\n";
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    return 0;
}
