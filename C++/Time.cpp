#include <iostream>
#include <iomanip>
using namespace std;
#define MAX 10
class time
{
	private:
		int hour;
		int min;
		int sec;
		int total;
	public:
		void getDetails(void);
		void putDetails(void);
		void cal(void);
};
void time::getDetails(void)
{
    cout << "Enter hours: " ;
    cin >> hour;
    cout << "Enter minutes: ";
    cin >> min;
    cout << "Enter secs: ";
    cin >> sec;
}
void time::putDetails(void)
{
	cout << "\nTime is=" << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec << "\n";
    cout << "Total Seconds:-\n";
    cout << total <<"secs\n";
}
void time::cal(void)
{
    total=(hour*60*60)+(min*60)+sec;
}
int main()
{
    time std[MAX];
    std[0].getDetails();
    std[0].cal();
    std[0].putDetails();
    return 0;
}
