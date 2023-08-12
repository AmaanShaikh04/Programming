#include <iostream>
using namespace std;
#define MAX 10
class Interest
{
	private:
		float principle;
		float time;
		float rate;
		static float interest;
	public:
		void getData(void)
		{
			cout << "Enter Principle:\n";
			cin >> principle;
			cout << "Enter Time Duration:\n";
			cin >> time;
			cout << "Enter Rate:\n";
			cin >> rate;
		}
		void Cal(void)
		{
			interest=(principle*time*rate)/100;
		}
		void Display(void)
		{
			cout << "Interest is: " << interest << endl;
		}
};
float Interest::interest=0.0;
int main()
{
	Interest obj1;
	obj1.getData();
	obj1.Cal();
	obj1.Display();
	return 0;
}
