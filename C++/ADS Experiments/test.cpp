/*
	Name: Amaan Shaikh
	File name: copy.cpp
	Description: 
	Roll no: 55
*/

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class treenode
{
	public:
		char word[20];
		char meaning[20];
		treenode *left;
		treenode *right;
		treenode *curr;
		friend class dictionary;
};


class dictionary
{
	treenode *root;
	public:
		void insert();
		
		void inorder_r();
		void inorder_r(treenode *temp);
		
		void copy(dictionary);
		treenode *copy (treenode*);
		
		dictionary();
};


class queue
{
	treenode *data[30];
	int front,rear;
	public:
		queue()
		{
			front = rear = 1;
		}
		
		void enque(treenode *);
		treenode *deque();
		int qempty();
};

void queue::enque(treenode *temp)
{
	rear++;
	data[rear] = temp;
}

treenode *queue::deque()
{
	front++;
	return(data[front]);
}


dictionary::dictionary()
{
	root = NULL;
}

void dictionary::insert()
{
	treenode *curr;
	treenode *temp;
	char ch;
	temp = root;
	do
	{
		curr = new treenode;
		cout << "Enter a word: " << endl;
		cin >> curr->word;
		cout << "Enter a meaning: " << endl;
		cin >> curr->meaning;
		
		if (root == NULL)
		{
			root = curr;
		}
		else
		{
			int flag = 0;
			while (flag == 0)
			{
				int i = strcmp(curr->word, temp->word);
				if(i<0)
				{
					if (temp->left == NULL)
					{
						temp->left = curr;
						flag = 1;
					}
					temp = temp->left;
				}
				else if (i > 0)
				{
					if(temp->right == NULL)
					{
						temp->right = curr;
						flag = 1;
					}
					temp = temp->right;
				}
				else
				{
					cout << "\n Word already exists" << endl;
				}
			}
		}
		cout << "Do you want to add more number or name  to continue y/n: " << endl;
		cin >> ch;
	}while (ch == 'y');
}

void dictionary::inorder_r()
{
	inorder_r(root);
}
void dictionary::inorder_r(treenode *temp)
{
	if (temp!=NULL)
	{
		inorder_r(temp->left);
		cout<<temp->word<<":"<<temp->meaning<<'\t';
		inorder_r(temp->right);
	}
}

void dictionary::copy(dictionary t1)
{
	root = copy(t1.root);
}

treenode* dictionary::copy(treenode *root)
{
	treenode *temp;
	
	temp=NULL;
	
	if(root!=NULL)
	{
		temp = new treenode;
		strcpy(temp->word, root->word);
		temp->left=copy(root->left);
		temp->right=copy(root->right);
	}
	return temp;
}

int main()
{
	dictionary t1;
	dictionary t2;
	
	t1.insert();
	t1.inorder_r();

	t2.copy(t1);
	t1.inorder_r();
}
