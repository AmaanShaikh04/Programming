#include <iostream>
using namespace std;
#define MAX 10
class Book
{
    private:
        char book_name[30];
        int price;
        int no_of_pages;
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
    cout << "Enter No of pages: ";
    cin >> no_of_pages;
}
void Book::putDetails(void)
{
    cout << "Book details:-\n";
    cout << "Book name:"<< book_name << "\nPrice:" << price << "\nNo of Pages:" << no_of_pages <<"\n\n";
}
int main()
{
    Book std[MAX];
    int n,i;
    cout << "Enter total number of Books: ";
    cin >> n;
    for(i=0;i< n; i++){
        cout << "Enter details of the Book " << i+1 << ":-\n\n";
        std[i].getDetails();
    }
    cout << endl;
    for(i=0;i< n; i++){
        cout << "Details of the Book " << (i+1) << ":-\n\n";
        std[i].putDetails();
    }
    return 0;

}
