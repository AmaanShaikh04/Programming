#include <iostream>
using namespace std;
class Sum
{
	public:
		int s=0;
		Sum(int a)
		{
			int i;
			for(i=0;i<a;i++)
			{
				s+=i;
			}
			cout << "Sum: " << s;
		}
};
int main()
{	
	Sum obj1(5);
	return 0;
}
