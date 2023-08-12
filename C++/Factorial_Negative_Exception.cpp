//Write a program to find factorial of a given number and throw an exception if the number entered is negative.
#include <iostream>
using namespace std;
int main()
    {
        int a,i,fact=1;
        cout<<"Enter a number : ";
        cin>>a;
        try
        {
            if(a>0)
            {
                for(i=1;i<a+1;i++)
                fact=fact*i;
            cout<<"\nThe factorial is: " << fact;
            }
        else if(a<0)
            throw (a);
        }
catch(int a)
    {
        cout<<"\nPlease enter a positive number";
    }
}
