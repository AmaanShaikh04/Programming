#include <iostream>
using namespace std;
#define MAX 10
class Staff
{
	

	public:
		char name[30];
		char post[20];
		void getData(void);
		void putData(void);	
};
void Staff::getData(void)
{
	cout << "Enter name: \n" ;
    cin >> name;
    cout << "Enter post: \n" ;
    cin >> post;
}
void Staff::putData(void)
{
	cout << name << " has the post of HOD" << endl;
}
int main()
{
	Staff std[MAX];
    int n,i;
    cout << "Enter total number of Staff: \n";
    cin >> n;
    for(i=0;i< n; i++){
        cout << "Enter details of Staff " << i+1 << ":\n";
        std[i].getData();
    }
    cout << endl;
    string HOD="HOD";
    for(i=0;i< n; i++)
	{
		if(std[i].post==HOD)
        std[i].putData();
    }
    return 0;
}
