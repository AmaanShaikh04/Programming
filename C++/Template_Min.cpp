//Write a program to find minimum of two values of different types using generic function.
#include <iostream>
using namespace std;
template <class T>
T min(T &n1,T &n2)
{
    return (n2>n1)?n1:n2;
}
int main()
{
    int i1, i2;
    cout << "Enter two numbers:\n";
    cin >> i1 >> i2;
    cout << min(i1,i2) <<" is smaller." << endl;
    return 0;
}
