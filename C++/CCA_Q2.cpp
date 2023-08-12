#include <iostream> 
using namespace std;
#define MAX 10
void ABC()
{
    static int c=0;
    int i;
    for(i=0;i<10;i++)
    {
    	if(i%2==0)
    	cout << i << " ";
	}
}
int main()
{
	cout << "Even positive numbers till 10 are:\n";
    ABC();
    return 0;
}
