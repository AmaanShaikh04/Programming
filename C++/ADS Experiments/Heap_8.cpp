#include <iostream>

using namespace std;

class Heap{
    protected:
    int marks[20];
    int n;

    public:
    void accept();
    void display();
    void heap_sort();
    void adjust(int a[], int n, int i);
    void maxmin();
};

void Heap::accept(){
    cout<<"Enter the number of students appeared for the exam"<<endl;
    cin>>n;
    for(int i=0;i<20;i++){
        marks[i]=0;
    }
    for(int i=0;i<n;i++){
        cout << "Enter marks of Student"<< i <<" :";
        cin>>marks[i];
    }
}

void Heap::display(){
    for(int i=0; i<n; i++){
        cout << marks[i] << " ";
    }
}

void Heap::adjust(int a[], int n, int i){
    int j=0;
    int temp=0;
    while (2*i+1<=n)
    {
        j = 2*i+1;
        if((j+1<=n) && (a[j+1]>a[j])){
            j = j+1;
            
        }
        if (a[i] >= a[j]){
            break;
        }
        else{
            temp = a[i];
            a[i]=a[j];
            a[j] = temp;
            i = j;
        }
    }
    
}

void Heap::heap_sort(){
    int a=n;
   for(int k=(a/2)-1; k>=0; k--){
        adjust(marks,a-1,k);
   } 
   while(a>0){
    int temp=marks[0];
    marks[0]=marks[a-1];
    marks[a-1]=temp;
    n--;
    adjust(marks,a-1,0);
   }
}

void Heap:: maxmin(){
    cout<<"\nMax marks in the subject are : "<<marks[n-1]<<endl;
    cout<<"Min marks in the subject are : "<<marks[0]<<endl;
}

int main(){
    Heap h;
    h.accept();
    h.display();
    h.heap_sort();
    // h.display();
    h.maxmin();
}



