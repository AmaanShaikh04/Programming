#include<iostream>
using namespace std;

class node
{
    int ht;
    int data;
    node *left;
    node *right;
    friend class avl;
};

class avl
{
    public:
		node*root;
        int height(node*a);
        node *LR(node*a);
        node *LL(node*a);
        void insert();
        node *insert(node*,int,node*);
        void inorder();
        void inorder(node*);
};

int avl::height(node *root)
{
    int t1=-1,t2=-1,h;
    if(root!=NULL)
	{
        t1 = height(root->left);
        t2=height(root->right);
    }
    if(t1<t2)
        h=t2;
    else
        h=t1;
    return h+1;
}


void avl::insert()
{
    int key;
    char ch;
    node*root1 = root;
    do
	{
        cout<<"Enter the key to be inserted: ";
        cin>>key;
        root1=root;
        root1 = insert(root1,key,NULL);
        cout<<"\nDo you want to add another node?y/n\n";
        cin>>ch;
        }while(ch=='y' || ch=='Y');
}

node *avl::insert(node *root,int key,node *p)
{
    int BF;
    if(root==NULL)
    {
        root= new node;
        root->data=key;
        root->left=NULL;
        root->right-NULL;
    }

    else
	{
        if(root->data>key)
        {
	        root->left=insert(root->left,key,root);
	        BF=height(root->left)-height(root->right);
	        cout<<"\nBalance factor:"<<BF;

			if(BF==2 || BF==-2)
			{
                if(key<(root->left)->data)
                {
                    cout<<"\nLL rotation";
                    if(p==NULL)
                        root=LL(root);
                    else
                    {
                        if(root==p->left)
                        {
							root=LL(root);
	                        p->left=root;
                        }
                        else
                        {
                            root=LL(root);
                            p->right=root;
                        }
                    }
                }
                    
				if(key>(root->left)->data)
				{
	                cout<<"\nLR rotation";
	                if(p=NULL)
	                root=LR(root);
	
	                else
	                {
	                    if(root==p->left)
	                    {
	                        root=LR(root);
	                        p->left=root;
	                    }
	
	                    else
	                    {
	                        root=LR(root);
	                        p->right=root;
	                    }
	                }
				}
        	}
    	}
    }
	return root;
}

node *avl::LL(node * a)
{
    node *b;
    a->left = b->right;
    b->right= a;
    a->ht = height(a);
    b->ht = height(b);
    return b;
}

node *avl::LR(node * a)
{
    node *b,*c;
    b=a->left;
    c=b->right;
    a->left = c->right;
    b->right = c->left;
    c->left = b;
    c->right = a;
    a->ht = height(a);
    b->ht = height(b);
    c->ht = height(c);
    return c;
}

node *avl::RR(node *a)
{
	node *b;
	b=a->right;
	a->right=b->left;
	b->left=a;
	a->ht=height(a);
	b->ht=height(b);
	return b;
}

node *avl::RL(node *a)
{
	node *b,*c;
	b=a->right;
	c=b->left;
	a->right=c->left;
	b->left=c->right;
	c->left=a;
	c->right=b;
	a->ht=height(a);
	b->ht=height(b);
	c->ht=height(c);
	return c;
}

void avl::inorder()
{
	inorder(root);
}

void avl::inorder(node* temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout << temp->data;
		inorder(temp->right);
	}
}

int main()
{
    avl v;
    v.insert();
    v.inorder();
    return 0;
}
