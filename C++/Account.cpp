#include <iostream>
using namespace std;
#define MAX 10 
class Account
{
	private:
		int Account_no;
		int balance;
	public:
		void getDetails();
		void putDetails();
};
void Account::getDetails()
{
	cout << "Enter the account no of the Employee\n";
	cin >> Account_no;
	cout << "Enter the Balance\n";
	cin >> balance; 	
}
void Account::putDetails()
{
	if(balance>=5000)
	balance=balance+(balance/10);
	cout << "Name of the Employee: " << Account_no << endl;	
	cout << "Highest Balance of the Employee " << Account_no << ": " << balance << "\n\n";

}
int main()
{
	Account std[MAX];
    int n,i;
    cout << "Enter total number of Employees: \n";
    cin >> n;
    for(i=0;i< n; i++)
	{
        cout << "Enter details of Employee " << i+1 << ":\n";
        std[i].getDetails();
    }
    cout << endl;
    for(i=0;i< n; i++)
	{
        std[i].putDetails();
    }
    return 0;
}
	
