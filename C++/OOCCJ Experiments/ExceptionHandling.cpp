#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class Hotel
{
private:

    int income,age;
    string city;
    string room_type;

public:
    string cust_name;
        int cust_id;

    void accept()
	{
        cout << "Enter customer name: ";
        cin >> cust_name;

        cout << "Enter customer ID: ";
        cin >> cust_id;        
    }

    void display()
	{
        cout << "Customer Name: " << cust_name << endl;
        cout << "Customer ID: " << cust_id << endl;
        cout << "Customer Income: " << income << endl;
        cout << "Customer City: " << city << endl;
        cout << "Customer Room Type: " << room_type << endl;
    }

    int getage()
	{
        cout << "Enter customer age: ";
        cin >> age;

        if (age < 18 || age > 55)
		{
            throw invalid_argument("Age is not between 18 and 55");
        }

        return age;
    }

    int getincome()
	{
    	cout << "Enter customer income: ";
        cin >> income;
        
        if (income < 50000 || income > 100000)
		{
            throw invalid_argument("Income is not between 50000 and 100000");
        }

        return income;
    }

    string getcity()
	{
    	cout << "Enter customer city (Pune or Mumbai): ";
        cin >> city;
        
        if (city != "Pune" && city != "Mumbai") {
            throw invalid_argument("City is not Pune or Mumbai");
        }

        return city;
    }

    string getroom_type()
	{
    	cout << "Enter customer room type (Delux or Super Delux): ";
        cin >> room_type;
        
        if (room_type != "Delux" && room_type != "Super Delux")
		{
            throw invalid_argument("Room type is not delux or super delux");
        }

        return room_type;
    }
};

int main()
{
    try
	{
        ofstream fout("hotel_records.txt");

        for (int i = 0; i < 5; i++)
		{
            Hotel h;
            h.accept();

            int age = h.getage();
            int income = h.getincome();
            string city = h.getcity();
            string room_type = h.getroom_type();

            fout << h.cust_name << " " << h.cust_id << " " << age << " " << income << " " << city << " " << room_type << endl;

            h.display();
            cout << endl;
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

