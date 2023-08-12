//Database System
/*	*Microproject by
	*Mansi Mulik 	(16)
	*Anish Panwala 	(20)
	*Amaan Shaikh 	(28)
*/
#include <iostream>
#include <fstream>
#include <string.h>			//including header files
using namespace std;

//start of void write
//Used to write in a file
void write()
{
	int i,sal,ctr;
	string name,phone,pos;
	fstream p("F:\\College Stuff\\Submissions\\OOP-II\\Database.txt", ios::out);
	if(!p)
	{
		cout << "Unable to open the file." << endl;
	}
	else
	{
		p << "Sr.no\tName\tPhone\tSalary\tPosition";
		for(i=0,ctr=1;i<3;i++,ctr++)
		{
			cout  << "Enter Name, Phone number, Salary, Position" << endl;
			cin >> name >> phone >> sal >> pos;
			p << "\n" << ctr << "\t" << name << "\t" << phone << "\t" << sal << "\t" << pos;
		}
	}
	p.close();
}
//end of void write

//start of void app
//used to append in a file
void app()
{
	int i,sal,ctr;
	string name,phone,pos;
	fstream p("F:\\College Stuff\\Submissions\\OOP-II\\Database.txt", ios::app);
	if(!p)
	{
		cout << "Unable to open the file." << endl;
	}
	else
	{
		for(i=0,ctr=4;i<3;i++,ctr++)
		{
			cout  << "Enter Name, Phone number, Salary, Position" << endl;
			cin >> name >> phone >> sal >> pos;
			p << "\n" << ctr << "\t" << name << "\t" << phone << "\t" << sal << "\t" << pos;
		}
	}
	p.close();
}
//end of void app

//start of void read
//used to read from a file
void read()
{
	fstream p("F:\\College Stuff\\Submissions\\OOP-II\\Database.txt", ios::in);
	if(!p)
	{
		cout << "Unable to open the file." << endl;
	}
	else
	{
		string str;
		while(!p.eof())
		{
			getline(p,str);
			cout << str << endl;
		}
	}
	p.close();
}
//end of void read

//start of main
int main()
{
	int ch;
	while(true)
	{
		cout << "Enter your choice" << endl;
		cout << "1. Write\n2. Append\n3. Read\n4. Exit" <<endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				write();
				break;
			case 2:
				app();
				break;
			case 3:
				read();
				break;
			case 4:
				return 0;
			default:
				cout << "Wrong Choice" << endl;
		}
	}
}
//end of main
//EOF
