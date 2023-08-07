/*
	Filename: secondscalculate.cpp
	Description: To get time in HH:MM:SS format and covert it to seconds
	Author: Hrushikesh Pandit
	(c) 2020 Hrushikesh
*/

#include <iostream>

using namespace std;

// Class name: time
// Description: takes input of time in HH:MM:SS format and converts it to seconds
// Class members: int h, m, s, res; void get(), void convert(), void put().
class timeconvert
{
	public:
		int h, m, s, res;
	
		void get()
		{
			cout << "Enter time in HH:MM:SS(hours:minutes:seconds) format: ";
			cin >> h >> m >> s;
		}
		
		void convert()
		{
			res = (h * 3600) + (m * 60) + (s * 1);
		}
		
		void put()
		{	
			cout << h << "h:" << m << "m:" << s << "s ->\n" << res << " seconds.";
		}
};



int main()
{
	timeconvert t1;
	
	t1.get();
	t1.convert();
	t1.put();
	
	return 0;
}	
//EOF
