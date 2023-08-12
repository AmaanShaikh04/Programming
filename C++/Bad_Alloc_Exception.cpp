//Write a program to handle "bad_alloc" exception. (Allocate memory using new operator)
#include <iostream> 
#include <new>
int main() 
{ 
	try
	{ 
		int *my_arr=new int[1000000000000];
	}
	catch(std::bad_alloc & exception) 
	{ 
    	std::cerr << "bad_alloc detected: " << exception.what(); 
	}	
	return 0; 
} 
