#include<iostream>
using namespace std;
class A {
   public:
   class B {
      private:
      int num;
      public:
      void getData(int n) 
	  {
        num = n;
      }
      void putData() 
	  {
		num=num*num;
        cout<<"The square of the number is "<<num;
      }
   };
};
int main() 
{
	int a;
	cout << "Enter a number" << endl;
	cin >> a;
	A :: B obj;
	obj.getData(a);
	obj.putData();
	return 0;
}
