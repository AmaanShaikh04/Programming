#include<iostream>
using namespace std;

class tnode{
    int data;
    tnode *left;
    tnode *right;
    int lbit,rbit;
    public:
        tnode(){
            lbit=1;
            rbit=1;
        }
    friend class tbt;
};

class tbt{
    tnode *head;
    public:
        tbt(){
            head=new tnode;
            head->rbit=0;
            head->left=head->right=head;
        }
        void create();
        void inorder();
        tnode *inorder_succ(tnode *var);
        void preorder();
        void displayleaf();
};

void tbt::create(){
    char ch,choice;
    tnode * root = new tnode;
    cout<<"Enter root data "<<endl;
    cin>>root->data;
    head->lbit=0;
    root->left=root->right=head;
    head->left=root;
    root->lbit=root->rbit=1;
    do{
        tnode * temp=root;
        tnode *curr=new tnode;
         cout<<"Enter curr node data "<<endl;
        cin>>curr->data;
        int flag=1;
        while(flag==1){
            cout<<"Where do you want to attach this node to left(l)/right(r) of "<<temp->data<<endl;
            cin>>ch;
            if(ch=='l'){
                if(temp->lbit==1){
                    temp->left=curr;
                    temp->lbit=0;
                    curr->left=temp->left;
                    curr->right=temp;
                    curr->lbit=curr->rbit=1;
                    flag=0;
                    break;
                }
                else{
                    temp=temp->left;
                    flag=1;
                }
            }
                if(ch=='r'){
                    if(temp->rbit==1){
                        curr->right=temp->right;
                        temp->right=curr;
                        curr->left=temp;
                        curr->lbit=curr->rbit=1;
                        temp->rbit=0;
                        flag=0;
                        break;
                    }
                    else{
                        temp=temp->right;
                        flag=1;
                    }
                }
            }
            cout<<"Do you want to attach another node (y/n) ?"<<endl;
            cin>>choice;
        }while(choice=='y');
}

void tbt :: inorder(){
    cout<<"\nInorder traversal of TBT - "<< endl;
    tnode *temp=head;
    while(1){
        temp=inorder_succ(temp);
        if(temp!=head){
            cout<<temp->data<<endl;
        }
        else
            break;
    }
}

tnode * tbt :: inorder_succ(tnode * var){
    tnode * x=var->right;
    if(var->rbit == 0){
        while(x->lbit ==0)
            x=x->left;
    }
    return x;
}

void tbt :: preorder(){
    cout<<"\nPreorder traversal of TBT - "<< endl;
    tnode * temp=head->left;
    while(temp!=head){
        cout<<temp->data<<endl;
        while(temp->lbit == 0){
            temp=temp->left;
            cout<<temp->data<<endl;
        }
        while(temp->rbit == 1){
            temp=temp->right;
        }
        temp=temp->right;
    }
}

void tbt :: displayleaf(){
    cout<<"\nLeaf nodes of the TBT are - "<< endl;
    tnode * temp=head->left;
    while(temp!=head){
        if(temp->lbit==1 && temp->rbit==1){
            cout<<temp->data<<endl;
        }
        while(temp->lbit == 0){
            temp=temp->left;
            if(temp->lbit==1 && temp->rbit==1){
                cout<<temp->data<<endl;
            }
        }
        while(temp->rbit == 1){
            temp=temp->right;
        }
        temp=temp->right;
    }
}

int main(){
    tbt t;
    t.create();
    int ch;
    do{
    cout<<"-------------------------------------------------------"<< endl;
    cout<<"Choose the traversal method of tbt - "<< endl;
    cout<<"1.Preorder\n2.Inorder\n3.Display Leaf Nodes\n4.Exit"<<endl;
    cout<<"-------------------------------------------------------"<< endl;
    cin>> ch;
    switch(ch){
        case 1:
            t.preorder();
            break;
        case 2:
            t.inorder();
            break;
        case 3:
            t.displayleaf();
            break;
        case 4 :
            exit(0);
        default:
            cout<<"Choose correct option!"<<endl;
            break;
    }
    }while(1);
}
