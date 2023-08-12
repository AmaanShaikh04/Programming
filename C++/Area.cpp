#include<iostream>
using namespace std;
class Area
{
        float ar;
        public:
            area(float r)
            {
                ar=3.14*r*r;
            }
            area(float l,float b)
            {
                ar=l*b;
            }
            void display()
            {
            	cout << "Area: " << ar << "\n\n";
            }
};
int main()
{
	Area obj;
    int ch,i;
    float x,y;
    for(i=0;i<2;i++)
    {
	    cout << "1. Area of Circle\n";
	    cout << "2. Area of Rectangle\n";
	    cout << "Enter Your Choice :";
	    cin >> ch;
	    switch(ch)
	    {
	        case 1:
	        	cout << "\nEnter Radius of the Circle: ";
	        	cin >> x;
	        	obj.area(x);
	        	obj.display();
	        	break;
	        case 2:
	        	cout << "\nEnter Length and Breadth of the Rectangle:\n";
	        	cin >> x >> y;
	        	obj.area(x,y);
	        	obj.display();
	        	break;
	        default:
	        	cout << "Invalid Choice" ;
	    }
	}
    return 0;
}
