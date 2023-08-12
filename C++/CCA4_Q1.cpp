/*	*Write a function template to 
	*a.Sort the array of 5 elements of type integer, characterand double.(Use Bubble sort Technique.)
	*b.Search the given value in the array depending on user's choice. (Use Linear search Technique.)
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
class A
{
	public:
		template <typename Type1>
		void sort_search()
		{
			Type1 arr[5];
			Type1 temp;
			int result=0;
			cout << "Enter 5 elements:\n";
			for(int i=0;i<5;i++)
			{
				cout << "Enter Element " << i+1 << ": ";
				cin >> arr[i];
			}
			cout << "After Bubblesort\n";
			for(int i=5;i>0;i--)
			{
				for(int j=0;j<i;j++)
				{
					if(arr[j]>arr[j+1] && arr[j+1]!='\0')
					{
						swap(arr[j],arr[j + 1]);
					}
				}
			}
			for(int i=0;i<5;i++)
			{
				cout << "Element " << i+1 << ": " << arr[i] << endl;
			}
			cout << "Enter the value to find in array\n";
			cin >> temp;
			for(int i=0;i<5;i++)
			{
				if(arr[i]==temp)
				{
					result++;
				}
			}
			if(result>0)
			{
				cout << "Value " << temp << " is found " << result << " number of times\n";
			}
			else
			{
				cout << "Element not found\n";
			}
		}
}obj;
int main()
{
	cout << "Enter Values of Integer Datatype\n";
	obj.sort_search <int>();
	cout << "\nEnter Values of Character Datatype\n";
	obj.sort_search <char>();
	cout << "\nEnter Values of Double Datatype\n";
	obj.sort_search <double>();
	return 0;
}
