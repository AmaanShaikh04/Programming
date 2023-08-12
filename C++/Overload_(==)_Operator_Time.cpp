/*Write a program to create a class called Time having data members hours, mins and seconds. 
Accept data for two Time objects. 
Overload == operator to check whether two time objects are equal or not.*/
#include <iostream>
using namespace std;
class Time
{
	int hours,mins,seconds;
    public:
	    Time()
	    {
	        hours=0;
			mins=0;
			seconds=0;
	    }
	    Time(int hr, int m, int s)
	    {
	        hours=hr;
			mins=m;
			seconds=s;
	    }
	    friend bool operator == (Time &obj1,Time &obj2);
};
bool operator == (Time &obj1,Time &obj2)
{
    return (obj1.hours==obj2.hours && obj1.mins==obj2.mins && obj1.seconds==obj2.seconds);
}
int main()
{
	cout << "Experiment 3, Question 2\n";
    Time obj1(1,17,23);
    Time obj2(1,17,23);
    if(obj1 == obj2)
    {
        cout << "\nBoth the time values are equal\n";
    }
    else
    {
        cout << "\nBoth the time values are not equal\n";
    }
    return 0;
}
