#include <iostream>
using namespace std;
class mbike
{
	private:
		char brand_name[30];
		float avg;
		float dist;
		int CC;
	public:
		void getData()
		{
			cout << "Enter Brand name: ";
			cin >> brand_name;
			cout << "Enter average: ";
			cin >> avg;
			cout << "Enter distance in 1 litre: ";
			cin >> dist;
			cout << "Enter CC: ";
			cin >> CC;
		}
		void putData()
		{
			cout << "\nBrand name: " << brand_name;
			cout << "\nAverage: " << avg;
			cout << "\nDistance in 1 litre: " << dist;
			cout << "\nCC: " << CC;
		}
};
int main()
{
	mbike obj[5];
	int i;
	for(i=0;i<5;i++)
	obj[i].getData();
	for(i=0;i<5;i++)
	obj[i].putData();
	return 0;
}
