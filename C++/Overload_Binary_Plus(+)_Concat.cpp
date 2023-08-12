//Write a program to overload binary + operator to add (concatenate) to two strings.
#include <iostream>
#include <string.h>
using namespace std;
class Concat
{
	public:
    	char s1[25],s2[25];
	    Concat(char str1[],char str2[])
	    {
	        strcpy(this->s1, str1);	//used to copy the string value in another string
	        strcpy(this->s2, str2);
	    }
	    void operator + ()
	    {
	    	cout << "\nBefore Concatenation of strings: " << s1 << "," << s2 << endl;
	    	string s3=strcat(s1,s2);	//used to concatenate 2 strings
			cout << "\nAfter concatenation of strings: " << s3 << endl;
	    }
};
int main()
{
	cout << "Experiment 3, Question 1\n";
    char str1[] = "Hello";
    char str2[] = " World!!";
    Concat a1(str1, str2);
	+a1;
    return 0;
}
