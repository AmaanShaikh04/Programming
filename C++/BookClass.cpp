/*
  Filename: BookClass.cpp
  Description: To make a class of Book
  Author: Hrushikesh Pandit
  (c) 2020 Hrushikesh
*/

#include <iostream>

using namespace std;

// Class name: Book
//Description: Makes a class of book and performs input and output of the NameofBook, Author and the Price of it.
//Class is public
class Book
{
 public:
  char bookname[20], author[20];
  float price;
  
  void get()
  {
    cout << "\nEnter the name of the book:";
    cin >> bookname;
    cout << "\nEnter the name of the Author:";
    cin >> author;
    cout << "\nEnter the price of the book:";
    cin >> price;

  }
  
  void show()
  {
    cout << "\n\nName of the book: " << bookname << "\nAuthor:" << author << "\nPrice:" << price << "\n"; 
  }
};


int main()
{
    int i;
    Book b1;
    Book b2;
    
    b1.get();
    b2.get();
  
  if(b1.price > b2.price)
    b1.show();
  else
    b2.show();
  
    return 0;
}
//EOF
