#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Rec
{
    string name;
    string address;
    string phone;
};

void addRecord(Rec r)
{
    ofstream outFile("file.txt", ios::app);
    outFile << r.name << "," << r.address << "," << r.phone << endl;
    outFile.close();
}

void searchRecord(string name)
{
    ifstream inFile("file.txt");
    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        string recordName = line.substr(0, line.find(","));
        if (recordName == name)
        {
            found = true;
            cout << "Record found: " << line << endl;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found\n" << endl;

    inFile.close();
}

void updateRecord(string name)
{
    fstream file("file.txt");
    string line;
    bool found = false;

    while (getline(file, line))
    {
        string recordName = line.substr(0, line.find(","));
        if (recordName == name)
        {
            found = true;
            cout << "Enter updated address: ";
            getline(cin, line);
            line += ",";
            cout << "Enter updated phone: ";
            string phone;
            getline(cin, phone);
            line += phone;
            file.seekp(-line.length(), ios::cur);
            file.write(line.c_str(), line.length());
            cout << "\nRecord updated\n" << endl;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found\n" << endl;

    file.close();
}

void deleteRecord(string name)
{
    ifstream inFile("file.txt");
    ofstream outFile("temp.txt");
    string line;
    bool found = false;

    while (getline(inFile, line))
    {
        string recordName = line.substr(0, line.find(","));
        if (recordName != name) 
            outFile << line << endl;
		else 
            found = true;
    }

    if (found)
        cout << "\nRecord deleted\n" << endl;
	else 
        cout << "\nRecord not found\n" << endl;

    inFile.close();
    outFile.close();
    remove("file.txt");
    rename("temp.txt", "file.txt");
}

int main()
{
    int choice;
    string name;
    Rec r;

    do{
        cout << "Enter your choice:" << endl;
        cout << "1. Add record" << endl;
        cout << "2. Search record" << endl;
        cout << "3. Update record" << endl;
        cout << "4. Delete record" << endl;
        cout << "5. Exit" << endl;
        cout <<"\nChoice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                cout << "Enter name: ";
                getline(cin, r.name);
                cout << "Enter address: ";
                getline(cin, r.address);
                cout << "Enter phone: ";
                getline(cin, r.phone);
                addRecord(r);
                cout << "\nRecord added\n" << endl;
                break;
            case 2:
                cout << "Enter name to search: ";
                getline(cin, name);
                searchRecord(name);
                break;
            case 3:
                cout << "Enter name to update: ";
                getline(cin, name);
                updateRecord(name);
                break;
            case 4:
                cout << "Enter name to delete: ";
                getline(cin, name);
                deleteRecord(name);
                break;
            case 5:
            	return 0;
            default:
                cout << "Wrong Choice";
        }
    }while(true);
}
