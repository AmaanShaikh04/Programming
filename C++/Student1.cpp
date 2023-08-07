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
    cout << "Student details:\n";
    cout << "Name:"<< name << "\nRoll Number:" << rollNo << "\nTotal:" << total << "\nPercentage:" << perc << "%\nClass:" << class1;
}
int main()
{
    student std[MAX];
    int n,i;
    cout << "Enter total number of students: ";
    cin >> n;
    for(i=0;i< n; i++){
        cout << "Enter details of student " << i+1 << ":\n";
        std[i].getDetails();
    }
    cout << endl;
    for(i=0;i< n; i++){
        cout << "Details of student " << (i+1) << ":\n";
        std[i].putDetails();
    }
    return 0;
}
