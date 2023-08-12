#include<iostream>
using namespace std;

class avl_node{
    string word,meaning;
    avl_node *left,*right;
    friend class avlTree;
};

class avlTree{
    public:
    avl_node *root;
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node *balance(avl_node *);
        void insert();
        avl_node *insert(avl_node *,avl_node *);
        void display(avl_node *,int);
        void inorder(avl_node *);
        void preorder(avl_node *);
        void postorder(avl_node *);

        avlTree(){
            root = NULL;
        }
};

avl_node * avlTree :: ll_rotation(avl_node * parent){
    avl_node * temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

avl_node * avlTree :: rr_rotation(avl_node * parent){
    avl_node * temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

avl_node * avlTree :: lr_rotation(avl_node * parent){
    avl_node * temp = parent->left;
    parent->left = rr_rotation(temp);
    return (ll_rotation(parent));
}

avl_node * avlTree :: rl_rotation(avl_node * parent){
    avl_node * temp = parent->right;
    parent->right = ll_rotation(temp);
    return (rr_rotation(parent));
}

int avlTree :: diff(avl_node * temp){
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

int avlTree :: height(avl_node * temp){
    int h =0;
    if(temp!=NULL){
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height,r_height);
        h = max_height + 1;
    }
    return h;
}

avl_node * avlTree :: balance(avl_node * temp){
    int b_factor = diff(temp);
    if(b_factor >  1 ){
        if(diff(temp->left)>0)
            temp = ll_rotation(temp);
        else
            temp=lr_rotation(temp);
    }
    else if(b_factor < -1){
        if(diff(temp->right)>0)
            temp = rl_rotation(temp);
        else
            temp=rr_rotation(temp);
    }
    return temp;
}

avl_node * avlTree :: insert(avl_node * root,avl_node * temp){
    if(root == NULL){
        root = new avl_node();
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(temp->word < root->word){
        root->left = insert(root->left,temp);
        root = balance(root);
    }
    else if(temp->word > root->word){
        root->right = insert(root->right,temp);
        root = balance(root);
    }
    return root;
}

void avlTree :: insert(){
    char ch;
    do{
        avl_node * temp = new avl_node;
        cout<<"Enter the word to be inserted and its meaning : "<<endl;
        cin>>temp->word>>temp->meaning;
        root = insert (root, temp);
        cout<<"Do you want to insert the another node (y/n) ? "<<endl;
        cin>>ch;
    }while(ch=='y');
    display(root,1);
}

void avlTree :: display(avl_node * temp ,int level){
    if(temp!=NULL){
        display(temp->right,level+1);
        cout<<endl;
        if(temp == root)
        cout<<"Root : ";
        for(int i=0;(i<level && temp!=root);i++){
            cout<<"   ";
        }
        cout<<temp->word << " : " << temp->meaning<<endl;
        display(temp->left,level+1);
    }
}

int main(){
    avlTree t;
    t.insert();
}
