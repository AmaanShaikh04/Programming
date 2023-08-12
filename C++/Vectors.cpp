/*	1. Write a program to implement vector for integer values. Perform the following operations on the given vector:
    	a. Create vector of 10 elements.
    	b. Insert the value in vector at 4th position.
    	c. Multiply each element in the vector by a scalar value.
    	d. Display all vector elements.
    	e. Erase the element at 7th position in the vector.
    	f. Display the size of the vector.
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> x(10);
    int i,a,b,num;
    cout << "Enter elements:\n";
    for(i=0;i<10;i++) 
    {
        cin >> a;
        x[i]=a;
    }
    cout << "\nCurrent Vector:\n";
    for(i=0;i<x.size();i++) 
    {
        cout << x[i] << " ";
    }
    cout << "\n\n";

    vector <int>::iterator p=x.begin();
    p=p+3; 
    cout << "Enter element to be inserted:\n";
    cin >> b;
    x.insert(p,1,b);
    cout << "\nCurrent Vector:\n";
    for(i=0; i<x.size(); i++) 
    {
        cout << x[i] << " ";  
    }
    cout << "\n\n";
    cout << "Enter a number which should be multiplied with the elements\n";
    cin >> num;
    for(i=0;i<x.size();i++)
    {
        x[i]=x[i]*num;
    }
    cout << "\nCurrent Vector:\n";
    for(i=0; i<x.size(); i++) 
    {
        cout << x[i] << " ";  
    }
    cout << "\n\n";
    p = x.begin();
    p += 6; 
    x.erase(p, p+1); 
    cout << "\nCurrent Vector:\n";
    for(i=0; i<x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n\n";
    cout << "Size of the vector = " << x.size() << endl;

}
