#include <iostream>
using namespace std;
#define MAX 10
class student
{
    private:
        char name[30];
        char class1[20];
        int rollNo;
        int total;
        float perc;
    public:
        void getDetails(void);
        void putDetails(void);
};
void student::getDetails(void)
{
    cout << "Enter name: " ;
    cin >> name;
    cout << "Enter roll number: ";
    cin >> rollNo;
    cout << "Enter class: " ;
    cin >> class1;
    cout << "Enter total marks outof 500: ";
    cin >> total; 
    perc=(float)total/500*100;
}
void student::putDetails(void)
{
	cout << "\nEnter details of student:\n";
	this->getDetails();
	cout << "\nStudent details:\n";
    cout << "Name:"<< name;
	cout << "\nRoll Number:" << rollNo;
	cout << "\nTotal:" << total;
	cout << "\nPercentage:" << perc;
	cout << "%\nClass:" << class1;
}
int main()
{
    student std[MAX];
    cout << "Details of student:\n";
    std[1].putDetails();
    return 0;
}
