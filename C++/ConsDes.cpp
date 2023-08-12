//WAP using constructor and destructor for a class that should display the object number being created/destroyed of this type
#include <iostream>
using namespace std;
class objects
{
	public:
		static int countCreate, countDestroy;
		objects()
		{
			++ countCreate;
			cout << "Object " << countCreate << " created\n";
		}
		~objects()
		{
			++ countDestroy;
			cout << "\nObject " << countDestroy << " destroyed";
			if(countDestroy == 5)
			{
				cout << endl;
			}	
		}
};
int objects::countCreate;
int objects::countDestroy;
int main(int argc, char const *argv[])
{
	objects obj1, obj2, obj3, obj4, obj5;
	return 0;
}

