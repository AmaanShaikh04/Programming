#include <iostream>
using namespace std;
#define MAX 10
class Book
{
    private:
        char book_name[30];
        int price,pages;
        char au_name[30];
    public:
        void getDetails(void);
        void putDetails(void);
};
void Book::getDetails(void)
{
    cout << "Enter name of the book: " ;
    cin >> book_name;
    cout << "Enter price of the book: ";
    cin >> price;
    cout << "Enter no of pages: ";
    cin >> pages;
    cout << "Enter Author's name': ";
    cin >> au_name;
}
void Book::putDetails(void)
{
    cout << "Book details:-\n";
    cout << "Book name:"<< book_name;
	cout << "\nPrice:" << price;
	cout << "\nPages:" << pages;
	cout << "\nAuthor's Name:" << au_name <<"\n\n";
}
int main()
{
    Book std[MAX];
    Book *p;
    p=std;
    int n,i;
    cout << "Enter total number of Books: ";
    cin >> n;
    for(i=0;i< n; i++){
        cout << "Enter details of the Book " << i+1 << ":-\n\n";
        p->getDetails();
    }
    cout << endl;
    for(i=0;i< n; i++){
        cout << "Details of the Book " << (i+1) << ":-\n\n";
        p->putDetails();
    }
    return 0;

}
