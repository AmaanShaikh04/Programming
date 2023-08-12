// Vector Program
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector <int> & l)	
{
	for(int i=0; i<l.size(); i++)
	{
	cout<<l[i]<<"\t";
	}
}

void accept(vector <int> & l)
{
	int x;
	cout<<"Enter list element"<<endl;
	cin>>x;
	l.push_back(x);
}
void del(vector<int>& l)
{
	int x;
	cout<<"Enter index to be deleted"<<endl;
	cin>>x;
	if(x>=0 && x<=l.size())
	{
		l.erase(l.begin()+x);
	}
}

void sorts(vector <int>  & l)
{
	sort(l.begin(),l.end());
}

int main()
{
	vector <int> list;
	int ch;
	while(1)
	{
		cout<<"1.Accept\n2.Display\n3.Delete\n4.Sort\n5.Find\n6.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				accept(list);
			break;
			case 2:
				display(list);
			break;
			case 3:
				del(list);
			break;
			case 4:
				sorts(list);
			break;
			case 5:
				//search(list);
			case 6:
				return 0;
			default:
				cout<<"Invalid choice"<<endl;
		}
		cout<<endl;
	}
}

