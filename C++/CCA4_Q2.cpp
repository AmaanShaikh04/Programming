/*	*Write a class template to
	*a.Create a stack of any type of 10 elements depending on the user's choice.
	*b.Pop 3 Values from s.
	*c.Display Stack data
*/
#include<iostream>
using namespace std;
#define SIZE 10
int t=-1;
template <class Type>
class abc
{
	private:
		Type s[SIZE];
	public:
		void push()
		{
			int no;
			cout << "Enter number of element to Push: \n";
			cin >> no;
			if(no>SIZE)
			{
				cout << "Error!\n";
			}
			else if((t+no)>SIZE-1)
			{
				cout << "Stack Overflow\n";
			}
			else
			{
				for(int i=0;i<no;i++,t++)
				{
					cout << "Enter Element " << i << ": ";
					cin >> s[i];
				}
			}
		}
		void pop()
		{
			int no;
			cout << "Enter number of element to Pop: \n";
			cin >> no;
			if(t==-1)
			{
				cout << "Stack Underflow\n";
			}
			else if(no>t+1)
			{
				cout << "Stack Underflow\n";
			}
			else
			{
				for(int i=0;i<no;i++)
				{
					Type temp=s[t];
					t--;
					cout << "The data popped is: " << temp << endl;
				}
			}
		}
		void print()
		{
			if(t==-1)
			{
				cout << "Stack Underflow\n";
			}
			else
			{
				for(int i=t;i>=0;i--)
				{
					cout << "Stack[" << i << "]= " << s[i] << endl;
				}
			}
		}
};
int main()
{
	int choice, choice2, data_choice;
	cout << "1.Integer\n";
	cout << "2.Character\n";
	cout << "3.Double\n";
	cout << "Enter your choice: ";
	cin >> data_choice;
	do
	{
		cout << "1.Stack Creation\n";
		cout << "2.Stack Deletion\n";
		cout << "3.Stack Printing\n";
		cout << "Enter your Choice: ";
		cin >> choice;
		switch (data_choice)
		{
			case 1:
			{
				abc<int> ol;
				switch (choice)
				{
					case 1:
					{
						ol.push();
						break;
					}
					case 2:
					{
						ol.pop();
						break;
					}
					case 3:
					{
						ol.print();
						break;
					}
					default:
					{
						cout << "\nEnter the Correct Choice" << endl;
					}
				}
				break;
			}
			case 2:
			{
				abc<char> ol;
				switch (choice)
				{
					case 1:
					{
						ol.push();
						break;
					}
					case 2:
					{
						ol.pop();
						break;
					}
					case 3:
					{
						ol.print();
						break;
					}
					default:
					{
						cout << "Enter the Correct Choice" << endl;
					}
				}
				break;
			}
			case 3:
			{
				abc<double> ol;
				switch (choice)
				{
					case 1:
					{
						ol.push();
						break;
					}
					case 2:
					{
						ol.pop();
						break;
					}
					case 3:
					{
						ol.print();
						break;
					}
					default:
					{
						cout << "Enter the Correct Choice" << endl;
					}
				}
				break;
			}
			default:
			{
				cout << "Enter Correct Choice" << endl;
			}
		}
		cout << "Do you want to Continue?\n";
		cout << "1.Yes\n";
		cout << "2.No\n";
		cin >> choice2;
	}while(choice2==1);
	return 0;
}
