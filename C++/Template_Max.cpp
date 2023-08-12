//Write a generic function to find the maximum of two integer values, two double values and two character values
#include <iostream>
using namespace std;
template <class T>
T max(T &n1,T &n2)
{
    return (n1>n2)?n1:n2;
}
int main()
{
    int i1, i2;
    double d1, d2;
    char c1, c2;
    cout << "Enter two Integers:\n";
    cin >> i1 >> i2;
    cout << "Enter two Double numbers:\n";
    cin >> d1 >> d2;
    cout << "Enter two Characters:\n";
    cin >> c1 >> c2;
    cout << max(i1,i2) <<" is larger." << endl;
    cout << max(d1,d2) <<" is larger." << endl;
    cout << max(c1,c2) << " has larger ASCII value.";
    return 0;
}
