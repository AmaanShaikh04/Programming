#include<iostream>
#include<cstring>
#define MAX 10
using namespace std;

class Employee
{
	int eid;
	string ename;
	string design;
	public:
	Employee()
	{
		eid=1;
		ename="";
		design="";
	}
	friend class Hash;
};

class Hash
{
	Employee HT[MAX];
	public:
	Hash()
	{
		for(int i=0;i<MAX;i++)
		{
			HT[i].eid=-1;
		}
	}
	void linear_without();
	void display();
	void linear_with();
};

void Hash::linear_without()
{
	Employee e;
	char ch='y';
	int index, flag=0, i;
	do
	{
		cout<<"Enter Employee id"<<endl;
		cin>>e.eid;
		cout <<"Enter Name"<<endl;
		cin>>e.ename;
		cout <<"Enter Designation"<<endl;
		cin>>e.design;
		
		index=e.eid%MAX;
		if(HT[index].eid==-1)
		{
			HT[index]=e;
		}
		else
		{
			i=1;
			i=(index+i)%MAX;
			while(i!=index)
			{
				if(HT[i].eid==-1)
				{
					HT[i]=e;
					flag=1;
					break;
				}
				i=(i+1)%MAX;
			}
			if(flag==0)
			{
				cout<<"Hash Table is Full\n";
				break;
			}
		}
		display();
		cout<<"Do you want to continue?"<<endl;
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}

void Hash::display()
{
	cout<<"Index\tEid\tName\tDesignation"<<endl;
	for(int i=0;i<MAX;i++)
	{
		cout<<i<<"\t"<<HT[i].eid<<"\t"<<HT[i].ename<<"\t"<<HT[i].design<<endl;
	}
}

void linear_with()
{
	
}	

void retrieve()
{
	
}

int main()
{
	Hash h;
	h.linear_without();
	return 0;
}
