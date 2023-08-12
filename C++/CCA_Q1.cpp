#include <iostream>
using namespace std;
#define MAX 10
class distance2;
class distance1
{
    public:
        float m,cm;
    public:
        void getData()
        {
            cout<<"Enter Data in Meter: ";
            cin>>m;
            cout<<"Enter Data in Centimeter: ";
            cin>>cm;
        }
        friend void sum(distance1 d1,distance2 d2);
};
class distance2
{
    double f,inc;
    public:
        void getData()
        {
            cout<<"Enter Data in Feet: ";
            cin>>f;
            cout<<"Enter Data in inches: ";
            cin>>inc;
        }
    	friend void diff(distance1 d1,distance2 d2);
        friend void sum(distance1 d1,distance2 d2);
};
void sum(distance1 d1,distance2 d2)
{
        int n1,n2,n3,ans,m,c,f,in;
        n1=d2.inc*2.54;
        n2=d2.f*0.30;
        n3=d1.m*100;
        ans=((d1.cm+n3)+(n1+n2));
        m=ans/100;
        c=ans%100;
        cout<<"\n"<<m<<" mtrs & "<<c<<" cms\n";
        f=m/0.30;
        in=c/2.54;
        cout<<f<<" feets & "<<in<<" inches";
}
int main()
{
    distance1 d1;
    distance2 d2;
    d1.getData();
    d2.getData();
    sum(d1,d2);
    return 0;
}
