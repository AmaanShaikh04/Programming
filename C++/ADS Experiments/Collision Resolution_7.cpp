#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class employee{
    int id;
    char name[20];
    double salary;
    friend class hashing;
};

class hashing{
    public:
    hashing(){
        int i;
        employee e;
        fstream file("data.txt",ios::app|ios::binary);
        file.seekp(0,ios::end);
        for(i=0;i<10;i++){
            e.id=-1;
            strcpy(e.name,"----");
            e.salary=-1;
            file.write((char*)&e,sizeof(e));
        }
        file.close();
    }

    void display();
    void linearprobwrep();
    void linearprobworep();
};

void hashing::display(){
    int i;
    employee a;
    cout<<" Id "<<"|"<<"  Name  "<<"|"<<" Salary "<<endl;
    ifstream file("data.txt",ios::in|ios::binary);
    while(file.read((char*)&a, sizeof(a))){
        cout<<"  "<< a.id <<"   "<<a.name<<"   "<<a.salary<<endl;
    }
    file.close();
}

void hashing::linearprobworep(){
    employee e;
    int loc,i;
    char ch;
    fstream file("data.txt",ios::in|ios::out|ios::binary);
    do{
        fflush(stdin);
        file.seekp(0,ios::beg);
        cout<<"Enter the employee's id,name and salary - "<<endl;
        cin>> e.id >> e.name >> e.salary;
        loc=e.id%10;
        employee temp;
        file.seekg((long int)loc*sizeof(e),ios::beg);
        file.read((char *)&temp,sizeof(temp));
        if(temp.id==-1){
            cout<<"Inside first loop\n";
            file.seekp((long int)loc*sizeof(temp),ios::beg);
            file.write((char *)&e,sizeof(e));
        }
        else{
            cout<<"Inside else loop\n";
            for(i=(loc+1)%10;i!=loc;i++){
                file.seekg((long int)i*sizeof(e),ios::beg);
                file.read((char *)&temp,sizeof(temp));
                if(temp.id== -1){
                    cout<<"Inside If\n";
                    file.seekp((long int)i*sizeof(e),ios::beg);
                    file.write((char *)&e,sizeof(e));
                    break;
                }
            }
            if(i==loc)
                cout<<"Hash Table Full";
        }
        file.flush();
        display();
        cout<<"Do you want to continue (y/n)?"<<endl;
        cin>>ch;
    }while(ch=='y');
}

void hashing::linearprobwrep(){
    employee e;
    int loc, i, newloc;
    char ch;
    fstream file("data.txt", ios::in | ios::out | ios::binary);
    do {
        fflush(stdin);
        file.seekp(0, ios::beg);
        cout<<"Enter the employee's id,name and salary - "<<endl;
        cin>> e.id >> e.name >> e.salary;
        loc=e.id%10;
        employee temp;
        file.seekg((long int)loc * (sizeof(e)), ios::beg);
        file.read((char*)&temp, sizeof(temp));
        if (temp.id == -1) {
            cout << "Inside first if\n";
            file.seekp((long int)loc * sizeof(e), ios::beg);
            file.write((char*)&e, sizeof(e));
        } else {
            newloc = temp.id % 10;
            if (newloc == loc) {
                for (i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    file.seekg((long int)i * sizeof(e), ios::beg);
                    file.read((char*)&temp, sizeof(temp));
                    if (temp.id == -1) {
                        cout << "Inside if\n";
                        file.seekp((long int)i * sizeof(e), ios::beg);
                        file.write((char*)&e, sizeof(e));
                        break;
                    }
                }
            } else {
                employee temp1 = temp;
                file.seekp(loc * sizeof(e), ios::beg);
                file.write((char*)&e, sizeof(e));
                for (i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    file.seekg(i * sizeof(e), ios::beg);
                    file.read((char*)&temp, sizeof(temp));
                    if (temp.id == -1) {
                        file.seekp(i * (sizeof(e)), ios::beg);
                        file.write((char*)&temp1, sizeof(temp1));
                        break;
                    }
                }
            }
        }
        if (i == loc) {
            cout << "Hash table full";
        }
        file.flush();
        display();
        cout << "Do you want to continue?";
        cin >> ch;
    } while (ch == 'y');
}


int main(){
    hashing h;
    h.display();
    int ch;
    do{
        cout<<"Choose the type of Collision Resolution Technique you want to implement : "<<endl;
        cout<<"1.Linear Probing with Replacement\n2.Linear Probing without Replacement\n3.Exit"<<endl;
        cin>>ch;
        switch(ch){
            case 1 : 
                h.linearprobwrep();
                break;
            case 2 :
                h.linearprobworep();
                break;
            case 3 :
                exit(0);
        }
    }while(1);
}
