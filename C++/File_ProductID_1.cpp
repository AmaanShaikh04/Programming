#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void app()
{
	int id,qua,r,i;
	string name;
	fstream p("F:\\College Stuff\\Submissions\\OOP-II\\stock.txt", ios::app);
	if(!p)
	{
		cout << "Unable to open the file." << endl;
	}
	else
	{
		for(i=0;i<2;i++)
		{
			cout  << "Enter Product ID, Name, Quantity, Rate" << endl;
			cin >> id >> name >> qua >> r;
			p << "\n" << id << "\t" << name << "\t" << qua << "\t\t" << r;
		}
	}
	p.close();
}
void read()
{
	fstream p("F:\\College Stuff\\Submissions\\OOP-II\\stock.txt", ios::in);
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
int main()
{
	int ch;
	while(true)
	{
		cout << "Enter your choice" << endl;
		cout << "1.Append\n2.Read\n3.Exit" <<endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
				app();
				break;
			case 2:
				read();
				break;
			case 3:
				return 0;
			default:
				cout << "Wrong Choice" << endl;
		}
	}
}
