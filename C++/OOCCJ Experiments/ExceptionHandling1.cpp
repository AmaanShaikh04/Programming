#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
	int income,age,cust_id,ch;
    string city,room_type,cust_name;
    try
	{
        ofstream fout("hotel_records1.txt");

		while(true)
		{
			cout << "Press 1 to insert in file" << endl;
			cout << "Press 2 to display the file" << endl;
			cout << "Press 3 to exit" << endl;
			cin >> ch;
			switch(ch)
			{
				case 1:
					cout << "Enter customer name: ";
			        cin >> cust_name;
			
			        cout << "Enter customer ID: ";
			        cin >> cust_id;   
		
		            cout << "Enter customer age: ";
			        cin >> age;
			
			        if (age < 18 || age > 55)
					{
			            throw invalid_argument("Age is not between 18 and 55");
			        }
			
		            cout << "Enter customer income: ";
			        cin >> income;
			        
			        if (income < 50000 || income > 100000)
					{
			            throw invalid_argument("Income is not between 50000 and 100000");
			        }
		
		            cout << "Enter customer city (Pune or Mumbai): ";
			        cin >> city;
			        
			        if (city != "Pune" && city != "Mumbai")
					{
			            throw invalid_argument("City is not Pune or Mumbai");
			        }
		
		            cout << "Enter customer room type (Delux or Super Delux): ";
			        cin >> room_type;
			        
			        if (room_type != "Delux" && room_type != "Super Delux")
					{
			            throw invalid_argument("Room type is not delux or super delux");
			        }
		
		            fout << cust_name << " " << cust_id << " " << age << " " << income << " " << city << " " << room_type << endl;
		        break;
		            
		        case 2:
		        	cout << "Customer Name: " << cust_name << endl;
			        cout << "Customer ID: " << cust_id << endl;
			        cout << "Customer Income: " << income << endl;
			        cout << "Customer City: " << city << endl;
			        cout << "Customer Room Type: " << room_type << endl;
		            cout << endl;
		        break;
		        
		        case 3:
		        	return 0;
		        	
		        default:
		        	cout << "Wrong Choice!" << endl;
			}
        }
        fout.close();
    }
    catch (const exception& e)
	{
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

