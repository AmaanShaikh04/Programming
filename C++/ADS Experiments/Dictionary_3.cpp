#include<iostream>
#include<string.h>
using namespace std;

class dnode{
    char word[20];
    char meaning[20];
    dnode *rightc;
    dnode *leftc;
    friend class dictionary;
    friend class queue;
};

class dictionary{
    dnode *root;
    public:
        void create();
        void inorder();
        void inorder(dnode *var);
        void remove(char key[20]);
        void copytree(dictionary d);
        dnode* copytree(dnode *copy); 
        void copytree_nr(dnode *root);
        void mirror();
        void mirror(dnode *root);
        void mirror_nr();
        void mirror_nr(dnode *root);
        void display();
        void modify();
        void displaybfs();
        dictionary();
};

class stack{
    int top;
    dnode *st[30];
    public:
        stack(){
            top=-1;
        }

        void push(dnode * temp);
        dnode *pop();
        int isempty();
        friend class dictionary;
};

void stack::push(dnode * temp){
    top++;
    st[top]=temp;
}

int stack::isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

dnode * stack::pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return NULL;
    }
    else{
        dnode * temp = st[top];
        top--;
        return temp;
    }
}

class queue{
    dnode* que[30];
    int front,rear;
    public:
        queue(){
            rear= front = -1;
        }
        void enque(dnode * temp);
        dnode * deque();
        int isempty();
        friend class queue;
};

void queue :: enque(dnode * temp){
    rear++;
    que[rear]=temp;
}

dnode * queue::deque(){
    front++;
    return que[front];
}

int queue :: isempty(){
    if(front==rear)
        return 1;
    else 
        return 0;
}

dictionary::dictionary(){
    root = NULL;
}

void dictionary::create(){
    char ch;
    dnode *temp;
    dnode *curr;
    // cout<<"Enter root (word) : " ;
    // cout<<"Enter meaning of " << root->word<<"- " ;
    do{
        temp=root;
        curr= new dnode;
        cout<<"Enter current (word) : " ;
        cin >> curr->word;
        cout<<"Enter meaning of " << curr->word<<" - " ;
        cin >> curr->meaning;
        // root->leftc = root->rightc = NULL;
        // curr->rightc = curr->leftc = NULL;
        if(root==NULL){
            root=curr;
        }
        else{
            int flag=1;
        while(flag==1){
            int i = strcmp(curr->word,temp->word);
            if(i<0){
                if(temp->leftc==NULL){
                    temp->leftc = curr;
                    flag =0;
                    break;
                }
                else{
                    temp=temp->leftc;
                    flag=1;
                }
            }
            else if(i>0){
                if(temp->rightc==NULL){
                    temp->rightc = curr;
                    flag=0;
                    break;
                }
                else{
                    temp=temp->rightc;
                    flag=1;
                }
            }
            else{
                cout<<"Word already exists!"<<endl;
            }
        }
        }
        cout<<"Do you want to add another word(y/n)?"<<endl;
        cin>>ch;
    }while(ch=='y');
    
}

void dictionary :: copytree(dictionary d){
   root = copytree(d.root);
}

dnode* dictionary :: copytree(dnode *root){
    dnode * temp=NULL;
    if(root!=NULL){
        temp= new dnode;
        strcpy(temp->word,root->word);
        strcpy(temp->meaning,root->meaning);
        temp->leftc = copytree(root->leftc);
        temp->rightc = copytree(root->rightc);
    }
    return temp;
}

void dictionary :: mirror(){
    mirror(root);
}

void dictionary :: mirror(dnode *root){
    dnode * temp=NULL;
    // temp=new dnode;
    temp= root->leftc;
    root->leftc = root->rightc;
    root->rightc = temp;
    if(root->leftc!=NULL){
        mirror(root->leftc);
    }
    if(root->rightc!=NULL){
        mirror(root->rightc);
    }
}

// void copytree_nr(dnode *root){
//     dnode * temp= root;
//     root1 = new dnode;
//     dnode * temp1 =root1;
//     temp1->word = temp2->word;
//     temp1->meaning
// }

void dictionary :: mirror_nr(){
    mirror_nr(root);
}

void dictionary :: mirror_nr(dnode *root){
    dnode* temp=root;
    dnode * temp1=NULL;
    temp=new dnode;
    temp1=new dnode;
    queue q;
    q.enque(temp);
    while(q.isempty()==0){
        q.deque();
        temp1=temp->leftc;
        temp->leftc=temp->rightc;
        temp->rightc=temp1;
        if(temp->leftc!=NULL){
            q.enque(temp->leftc);
        }
        if(temp->rightc != NULL){
            q.enque(temp->rightc);
        }
    }
}

void dictionary::inorder(){
    inorder(root);
}

void dictionary::inorder(dnode *var){
    if(var!=NULL){
        inorder(var->leftc);
        cout << var->word <<" : "<<var->meaning<<endl;
        inorder(var->rightc);
    }
}

void dictionary::remove(char key[20]){
    dnode * temp;
    dnode *parent;
    dnode *curr;
    dnode *s,*s1;
    temp=root;
    while(temp!=NULL){
        int i =strcmp(key,temp->word);
        if(i<0){
            parent=temp;
            temp=temp->leftc;
        }
        else if(i>0) {
            parent=temp;
            temp=temp->rightc;
            }
            else{
                curr=temp;
                break;
            }
    }
            if(curr==root){
                if(curr->leftc !=NULL && curr->rightc ==NULL){
                    root=curr->leftc;
                }
                else if(curr->leftc ==NULL && curr->rightc !=NULL){
                    root= curr->rightc;
                }
                else if(curr->leftc !=NULL && curr->rightc !=NULL){
                    temp=curr->leftc;
                    root=curr->rightc;
                    s=curr->rightc;
                    while(s->leftc!=NULL){
                        s=s->leftc;
                    }
                    s->leftc=temp;
                }
            }

            if(curr->leftc==NULL && curr->rightc==NULL){
                if(curr == parent->leftc){
                    parent->leftc =NULL;
                }
                else{
                    parent->rightc = NULL;
                }
            }
            else if(curr->leftc !=NULL &&curr->rightc ==NULL){
                if(curr == parent->leftc){
                    parent->leftc = curr ->leftc;
                }
                else{
                    parent->rightc = curr->leftc;
                }
            }
            else if(curr->leftc ==NULL &&curr->rightc !=NULL){
                if(curr==parent->leftc){
                    parent->leftc = curr->rightc;
                }
                else{
                    parent->rightc=curr->rightc;
                }
            }
            else{
                s=curr->rightc;
                s1=s;
                temp=curr->leftc;
                while(s->leftc!=NULL){
                    s=s->leftc;
                }
                s->leftc=temp;
                if(curr==parent->leftc){
                    parent->leftc= s1;
                }
                else{
                    parent->rightc = s1;
                }
            // }
            delete(curr); 
    }           
}

int main(){
    char key[20];
    dictionary d1,d2;
    dictionary();
    d1.create();
    d1.inorder();
    // cout<<"Enter the word you want to delete - "<<endl;
    // cin>>key;
    // d1.remove(key);
    // d1.inorder();
    // d2.copytree(d1);
    // cout<<"Dictionary after copy operation - "<<endl;   
    // d2.inorder();
    // d1.mirror();
    // cout<<"Dictionary after mirror operation - "<<endl;
    // d1.inorder();
    

d1.mirror_nr();
cout<<"Dictionary after Non-Recursive mirror operation - " <<endl;
d1.inorder();
    return 0;
}
