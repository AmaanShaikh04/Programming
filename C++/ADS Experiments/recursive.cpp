/*
	Name: Amaan Shaikh
	File name: recursive.cpp
	Description: 
	Roll no: 55
*/

#include <iostream>
using namespace std;

class treenode
{
	int data;
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree
{
  treenode *root;
  public:
	  tree()
	  {
	  	root = NULL;
	  }
 
  void create();
  void create_rc();
  void create_rc(treenode *root);
 
  void display_ldr();
  void display_ldr(treenode *root);

  void display_lrd();
  void display_lrd(treenode *root);

  void display_dlr();
  void display_dlr(treenode *root);

   };


void tree::create()
{
	char ch1;
	if(root==NULL)
	{
		root = new treenode;
		cout << "Enter root note data" << endl;
		cin >> root->data;
	}
	do
	{
		treenode *temp, *curr;
		temp=root;
		int flag=0;
		curr = new treenode;
		cout << "Enter child data" << endl;
		cin >> curr->data;
		while(flag==0)
		{
			cout << "Where do you want to add? Left or Right" << endl;
			char ch;
			cin >> ch;
			if(ch=='l')
			{
				if(temp->left==NULL)
				{
					temp->left = curr;
					flag=1;
				}
				temp=temp->left;
			}
			else
			{
				if(ch=='r')
				{
					if(temp->right==NULL)
					{
						temp->right = curr;
						flag=1;
					}
					temp=temp->right;
				}
			}
		}

	cout << "Do you want to continue?"<<endl;
	cin >> ch1;
	}while(ch1=='y');
}

class stack
{
	int top;
	treenode *data[30];
	public:
		stack()
		{
			top=-1;
		}
		void push(treenode *temp);
		treenode *pop();
		int empty();
		friend class tree;
};

void stack::push(treenode *temp)
{
	top++;
	data[top]=temp;
}

treenode *stack::pop()
{
	if(top!=1)
	{
		treenode *temp = data[top];
		top--;
		return temp;
	}
}

void tree::create_rc()
{
	if(root==NULL)
	{
		root = new treenode;
		cout << "Enter root node data: " << endl;
		cin >> root->data;
	}
	create_rc(root);
}

void tree::create_rc(treenode *temp)
{
	char ch;
	cout << "Do you want to add to left?\nPress 'L' to add to left and any other letter to switch to adding in right" << endl;
	cin >> ch;

	if(ch=='l')
	{
		treenode *curr = new treenode;
		cout << "Enter child node data" << endl;
		cin >> curr->data;
		temp->left = curr;
		create_rc(curr);
	}
	cout << "Do you want to add to right?\nPress 'R' to add to Right and any other letter to exit" << endl;
	cin >> ch;

	if(ch=='r')
	{
		treenode *curr = new treenode;
		cout << "Enter child node data" << endl;
		cin >> curr->data;
		temp->right = curr;
		create_rc(curr);
	}
}

void tree::display_ldr()
{
	display_ldr(root);
}

void tree::display_ldr(treenode* temp)
{
	if(temp!=NULL)
	{
		display_ldr(temp->left);
		cout << " -> " << temp->data;
		display_ldr(temp->right);
	}
}

void tree::display_lrd()
{
	display_lrd(root);
}

void tree::display_lrd(treenode* temp)
{
	if(temp!=NULL)
	{
		display_lrd(temp->left);
		display_lrd(temp->right);
		cout << " -> " << temp->data;
	}
}

void tree::display_dlr()
{
	display_dlr(root);
}

void tree::display_dlr(treenode* temp)
{
	if(temp!=NULL)
	{
		cout<<" -> "<< temp->data;
		display_dlr(temp->left);
		display_dlr(temp->right);
	}
}

int main()
{
	tree t1;
	int r_rc_ch,ch3;
	cout << "Enter 1 for Recursive create\nEnter 2 for Non-Recursive create\nEnter choice: ";
	cin >> r_rc_ch;
	if(r_rc_ch==1)
		t1.create_rc();
	else if(r_rc_ch==2)
		t1.create();

	do
	{
		cout << "\n"<<endl;
		cout << "1.Inorder(ldr)"<<endl;
		cout << "2.Pre-order(dlr)"<<endl;
		cout << "3.Post-order(lrd)"<<endl;
		cout << "4.Exit"<<endl;
		cout << "\nChoice: ";
		cin >> ch3;
		cout << endl;

		switch(ch3)
		{
			case 1:
				t1.display_ldr();
				break;
			case 2:
				t1.display_dlr();
				break;
			case 3:
				t1.display_lrd();
				break;
		}
	}while(ch3!=4);
	return 0;
}