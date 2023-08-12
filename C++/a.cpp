#include <iostream>
using namespace std;
class X
{
	public:
		void r()
		{
			int i;
			for(i=0;i<10;i++)
			cout << i <<endl;
		}
		
};
int main()
{
	X *p;
	p->r();
	return 0;
}
