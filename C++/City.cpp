#include <iostream>
using namespace std;
#define MAX 10 
class city
{
	private:
		char name[30];
		int population[5];
	public:
		void getDetails();
		void putDetails();
};
void city::getDetails()
{
	int i,n=5;
	for(i=0;i<n;i++)
	{
		cout << "Enter details of city " << i+1 << ":\n";
		cout << "Enter the name of the city\n";
		cin >> name;
		cout << "Enter the population\n";
		cin >> population[i]; 	
	}
}
void city::putDetails()
{
	int i,max=population[0];
	for(i=0;i<5;i++)
	{
		if(population[i]>max)
		max=population[i];
	}
		cout << "Name of the city: " << name << endl;	
		cout << "Highest Population of the city " << name << ": " << max << "\n\n";

}
int main()
{
	city std[MAX];
	int n=5,i;
	std[1].getDetails();
	cout << endl;
	std[1].putDetails();
	return 0;
}
