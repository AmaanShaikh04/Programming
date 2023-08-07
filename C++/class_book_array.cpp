/* 
	File name : class_book_array.cpp
	Description: Get info of Book(title and author's name) and display it
*/

#include <iostream>
#include <string>

using namespace std;

// class name: Book
// Members: char title, author;
// 	    input(), and output(); 	
class Book
{
public:
	char title[20], author[20];
	
	void input()
	{
		cout << "\nEnter the name of the book:";
		cin >> title;
		cout << "\nEnter the author's name:";
		cin >> author;
	}
	
	void output()
	{
		cout << "\n\nName of Book:" << title << "\nAuthor:" << author << "\n"; 
	}
};

int main()
{
	Book b[5];
	int i;
	
	for(i = 0; i < 5 ; i ++)
	{
		b[i].input();		
	}
	
	for (i = 0; i < 5 ; i ++)
	{
		b[i].output();
	}	

	return 0;
}
