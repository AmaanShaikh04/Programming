/*
	Name: Amaan Shaikh
	File name: ComplexNumber.cpp
	Description: 
	Roll no: 55
*/

#include <iostream>
using namespace std;

class complex
{
	int re;
	int imag;
	
	public:
		
		complex()
		{
			re=0;
			imag=0;
		}
		
		complex(int r, int i)
		{
			re=r;
			imag=i;
		}		
		void getComplex()
		{
			cout << "Enter real number:" << endl;
			cin>>re;
			cout << "Enter imaginary number:" << endl;
			cin>>imag;
		}
		
		void printComplex()
		{
			cout << re << "+";
			cout << imag << "i\n" << endl;
		}
		
		complex operator + (complex c2)
		{
			complex temp;
			temp.re=re+c2.re;
			temp.imag=imag+c2.imag;
			return temp;
		}
		
		complex operator - (complex c2)
		{
			complex temp;
			temp.re=re-c2.re;
			temp.imag=imag-c2.imag;
			return temp;
		}
		
		complex operator * (complex c2)
		{
			complex temp;
			temp.re=re*c2.re;
			temp.imag=imag*c2.imag;
			return temp;
		}
		
		complex operator / (complex c2)
		{
			complex temp;
			temp.re=re/c2.re;
			temp.imag=imag/c2.imag;
			return temp;
		}
		
		complex operator ++ (int)
		{
			int r,i;
			r=re++;
			i=imag++;
			return complex(r,i);
		}
		
		complex operator ++ ()
		{
			int r,i;
			r=++re;
			i=++imag;
			return complex(r,i);
		}
		
		complex operator -- ()
		{
			int r,i;
			r=--re;
			i=--imag;
			return complex(r,i);
		}
		
		complex operator -- (int)
		{
			int r,i;
			r=re--;
			i=imag--;
			return complex(r,i);
		}
		
		friend ostream& operator << (ostream&, complex&);
		friend istream& operator >> (istream&, complex&);
};

ostream & operator << (ostream &out, complex &num)
{
	out << num.re << "+" << num.imag << "i";
	return(out);
}

istream & operator >> (istream &in, complex &num)
{
	cout << "Real: ";
	in >> num.re;
	cout << "\nImaginary: ";
	in >> num.imag;
	return(in);
}

int main()
{
	complex c1,c2,c3;
	int choice;
	do
	{
		cout << "Enter your choice: \n";
		cout << "Press 1 to Input data\n";
		cout << "Press 2 to Print data\n";
		cout << "Press 3 to Add\n";
		cout << "Press 4 to Subtract\n";
		cout << "Press 5 to Multiply\n";
		cout << "Press 6 to Divide\n";
		cout << "Press 7 to Increment (Postfix)\n";
		cout << "Press 8 to Increment (Prefix)\n";
		cout << "Press 9 to Decrement (Postfix)\n";
		cout << "Press 10 to Decrement (Prefix)\n";
		cout << "Press 11 to Input data (Friend Function)\n";
		cout << "Press 12 to Print data (Friend Function)\n";
		cout << "Press 0 to Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				c1.getComplex();
				c2.getComplex();
				break;
			case 2:
				c1.printComplex();
				c2.printComplex();
				break;
			case 3:
				c3=c1+c2;
				cout << "Addition of numbers is: ";
				c3.printComplex();
				break;
			case 4:
				c3=c1-c2;
				cout << "Substraction of numbers is: ";
				c3.printComplex();
				break;
			case 5:
				c3=c1*c2;
				cout << "Multiplication of numbers is: ";
				c3.printComplex();
				break;
			case 6:
				c3=c1/c2;
				cout << "Division of numbers is: ";
				c3.printComplex();
				break;
			case 7:
				c1++;
				c2++;
				c1.printComplex();
				c2.printComplex();
				break;
			case 8:
				++c1;
				++c2;
				c1.printComplex();
				c2.printComplex();
				break;
				break;
			case 9:
				c1--;
				c2--;
				c1.printComplex();
				c2.printComplex();
				break;
			case 10:
				--c1;
				--c2;
				c1.printComplex();
				c2.printComplex();
				break;
			case 11:
				cin >> c1;
				cin >> c2;
			case 12:
				cout << c1;
				cout << c2;
			case 0:
				return 0;
			default:
				cout << "Wrong Choice!!";
				return 0;
		}
	}while(true);
	return 0;
}

