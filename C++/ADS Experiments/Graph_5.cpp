#include<iostream>
using namespace std;

class gnode{
    int id;
     string name;
     gnode *next;
     friend class graph;
};

class graph{
    private:
        gnode *head[20];
        int n;
    public:
        graph(){
            int i;
            string str;
            cout<<"Enter the number of friends - ";
            cin >> n;
            for(i=0;i<n;i++){
                head[i] = new gnode;
                head[i]->id =i;
                cout<<"Enter the username - " ;
                cin >> str;
                head[i]->name = str;
                head[i]->next = NULL;
            }
        }

        void create();
        void display();
        void displaydft();
        void displaybfs();
        void displaydft_r();
        void displaydft_r(int id);
};

void graph :: create(){
    int i,id;
    char ch;
    string v;
    for(i=0;i<n;i++){
        gnode * temp = head[i];
        do{
            cout<<"Enter the friend's name for "<<head[i]->name<<" : " ;
            cin >> v;
            cout<<"Enter the friend's id ";
            cin >> id;
            if(v==head[i]->name){
                cout<<"Self loop are not allowed"<<endl;
            }
            else{
                gnode *curr = new gnode ;
                curr->id=id;
                curr->name = v ;
                temp->next=curr;
                temp=temp->next;
            }
            cout<<"Do you want to add another user (y/n) ? "<<endl;
            cin >> ch;
        }while(ch=='y');
    }
}

void graph :: display(){
    int i;
    cout<<"\nAdjacency List of the users : "<<endl;
    for(i=0;i<n;i++){
        gnode * temp = head[i];
        while(temp!=NULL){
            cout<<temp->id<<" : "<<temp->name<<endl;
            if(temp->next!=NULL){
                cout<<" -> ";
            }
            temp=temp->next;
        }
        cout<<endl;
    }
}

class stack{
    int top;
    int st[30];
    public:
        stack(){
            top=-1;
        }

        void push(int temp);
        int pop();
        int isempty();
        friend class graph;
};

void stack::push(int temp){
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

int stack::pop(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else{
        int temp = st[top];
        top--;
        return temp;
    }
}

class queue{
    int que[30];
    int front,rear;
    public:
        queue(){
            rear= front = -1;
        }
        void enque(int id);
        int deque();
        int isempty();
        friend class graph;
};

void queue :: enque(int id){
    rear++;
    que[rear]=id;
}

int queue::deque(){
    front++;
    return que[front];
}

int queue :: isempty(){
    if(front==rear)
        return 1;
    else 
        return 0;
}


void graph :: displaydft(){
    int id;
    int i;
    int visited[n];
    cout<<"\nEnter the starting vertex id : ";
    cin >> id;
    stack s;
    for(i=0;i<n;i++){
        visited[i]= 0;
    }
    visited[id]=1;
    s.push(id);

    while(s.isempty()!=1){
        int temp=s.pop();
        cout<< head[temp]->id << " : "<< head[temp]->name <<" "<<endl;
        gnode * t = head[temp]->next;
        while(t!=NULL){
            if(visited[t->id]==0){
                    s.push(t->id);
                    visited[t->id]=1;
                    }
            t=t->next;
                }
        }

    }

void graph :: displaybfs(){
    int id;
    int i;
    int visited[n];
    cout<<"\nEnter the starting vertex id : ";
    cin >> id;
    queue q;
    for(i=0;i<n;i++){
        visited[i]= 0;
    }
    visited[id]=1;
    q.enque(id);

    while(q.isempty()!=1){
        int temp=q.deque();
        cout<< head[temp]->id << " : "<< head[temp]->name <<" "<<endl;
        gnode * t = head[temp]->next;
        while(t!=NULL){
            if(visited[t->id]==0){
                    q.enque(t->id);
                    visited[t->id]=1;
                    }
            t=t->next;
                }
        }

    }

void graph:: displaydft_r(){
    int i,id,visited[n];
    for(i=0;i<n;i++){
        visited[i]= 0;
    }
    cout<<"\nEnter the starting vertex id : ";
    cin >> id;
    displaydft_r(id);
}

void graph:: displaydft_r(int id){
    cout<< head[id]->id << " : "<< head[id]->name <<" "<<endl;

}

int main(){
    int ch;
    graph g;
    g.create();
    do{
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Choose the method to display the graph -"<<endl;
    cout<<"1.Display DFT\n2.Display BFT\n3.Exit\n";
    cout<<"---------------------------------------------------"<<endl;
    cin>>ch;
    switch(ch){
        case 1:
            g.displaydft();
            break;
        case 2:
            g.displaybfs();
            break;
        case 3:
            exit(0);
        default:
            cout<<"Invalid Choice"<<endl;
    }
    }while(1);
}

