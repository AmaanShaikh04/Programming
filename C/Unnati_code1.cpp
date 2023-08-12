/*
	input: 
		10 subendu
		20 anjana
	
	output:
		20 : anjana
		10 : subendu
		20 : anjana
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class employee {
    int eid;
    char *name;
    public:
        employee(int eid_, const char *name_) : eid(eid_), name(strdup(name_)) { }
        employee(const employee &e) : eid(e.eid), name(strdup(e.name)) { }   // LINE-1
        employee& operator= (const employee &e){    // LINE-2 
            if (this != &e) {              // LINE-3 
                free(name);
                eid = e.eid;
                name = strdup(e.name);				
            }
            return *this;
        }
	void print()
	{
        cout << eid << " : " << name << endl;
    }
};

int main() {
    int i, j;
    char n1[80], n2[80];
    cin >> i >> n1 >> j >> n2;
   
    employee e1(i, n1);
    employee e2 = e1;
    employee e3(j, n2);
   
    e1 = e3;
    e1.print();
    e2.print();
    e3.print();
   
    return 0;
}
