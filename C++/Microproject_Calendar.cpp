/*
 *	File name:	Microproject_Calendar.cpp
 *	Description: Program based on a calendar.
 *	Authors: Amaan Shaikh, Mansi Mulik, Hrushikesh Pandit and Anish Panwala
 *	(c) 2020 A.M.H.A.
 */

//including all the header files required for the program to work

#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

using namespace std;

//Creating class calendar

class calender
{
	
	private:
		int date, month, year;
	
	public:
		
		calender(int d = 1,int m = 1,int y = 1700)
		{
		date = d;
		month = m;
		year = y;
		}
		
		//Declaration of functions required
		
		void day(int);
		void monthcal(int, int);
		bool leapyear(int);
		int DaysInMonth(int, int);
		int DayNumber(int, int, int);
};

// boolean function used to check if entered year is leap year or not 

bool calender::leapyear(int y)
{
	bool Leap;
	if ( (y % 4 == 0) && ( (y % 100 != 0) || (y % 400 == 0) ) )
	Leap = true;
	else
	Leap = false;
	return Leap;
}

//for returning the number of days in the entered month

int calender::DaysInMonth(int m, int y)
{
	//1,3,5,7,8,10,12:- 31 days
	//2:- if leap year then 29 days,else 28 days
	//4,6,9,11:- 30 days

	switch(m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if (leapyear(y))
			return 29;
			else
			return 28;
		default:
			return 30;
	}
}

//

int calender::DayNumber(int d, int m, int y)
{

	int i;
	int d1=6;
	for( i = 1583 ; i < y ; i++ )
	{
	d1 += (leapyear(i)) ? 2 : 1 ;
	d1 += 364;
	}
	for( i = 1 ; i < m ; i++ )
	d1 += DaysInMonth(i,y);
	d1 += d;
	return d1;

}

//for knowing the day of the given date, month and year

void calender::day(int a)
{

	switch(a)
	{

		case 1:
		cout << "Monday";
		break;
		case 2:
		cout << "Tuesday";
		break;
		case 3:
		cout << "Wednesday";
		break;
		case 4:
		cout << "Thursday";
		break;
		case 5:
		cout << "Friday";
		break;
		case 6:
		cout << "Saturday";
		break;
		case 0:
		cout << "Sunday";
		break;
		default:
		cout << "\a\a\a\n\nERROR!!!";

	}

}


void calender::monthcal(int month,int year)
{

	int i, mon, c;
	i = 0;
	for(i = 0 ; i <= 6 ; i++ )
	{

		day(i);
		cout << " ";

	}

	i = 1;
	c = DayNumber( --i, month, year);
	c = c % 7;
	cout << "\n";
	switch(c)
	{

		case 0:
		break;
		case 1:
		cout << "\t";
		break;
		case 2:
		cout << "\t\t";
		break;
		case 3:
		cout << "\t\t\t";
		break;
		case 4:
		cout << "\t\t\t\t";
		break;
		case 5:
		cout << "\t\t\t\t\t";
		break;
		case 6:
		cout << "\t\t\t\t\t\t";

	}

	//getting the number of days in a month
	mon = DaysInMonth(month, year);
	for(i = 1 ; i <= mon ; i++ )
	{

		cout << " " << i << "\t";
		c++;
		if (! (c % 7) )
		cout << "\n";

	}

}
//Main function, Start of program
int main()
{

	int x, y, z;

	//used to give color to the background
	system("color 9f");

	char ch;
	char t = '\xCD';
	
	//do-while loop used for executing the program
	do
	{

		//clearing screen
		system("cls");

		int i,date,year,month;
		cout << " _______________________________________________________________________________\n"
			<< "|\t\t\tWelcome to the Microproject_Calendar\t\t\t|\n"
			<< "|\t\t\t\t\t\t\t\t\t\t|\n"
			<< "|\t\t\tCalendar Microproject of SYCO\t\t\t\t|\n"
			<< "|_______________________________________________________________________________|\n"
			<< "\n\tChoose your option:\n"
			<< "\t\tEnter 1 for knowing the day of a specific date\n"
			<< "\t\tEnter 2 to view the calendar of any given month\n";
		cout << "\nEnter your choice: ";
		
		//accepting the choice entered by the user
		cin >> i;

		//year range 1700-2400
		if(i==1)
		{

			cout << "Enter date(dd): ";
			cin >> date;
			
			//checking if the date is valid
			if(date > 31 || date < 1)
			{

				cout << "\nPlease provide valid date.\nPress any key...\n";
				getch();
				system("cls");
				main();
				//clearing screen and calling main function again when the date is invalid

			}
			
			month:
			cout << "Enter month(mm): ";
			cin >> month;

			//checking if the month is valid
			if(month > 12 || month < 1)
			{

				cout << "\nPlease provide valid month.\nPress any key...\n";
				getch();
				system("cls");
				main();
				//clearing screen and calling main function again when the month is invalid

			}
			
			year:
			cout << "Enter year(yyyy): ";
			cin >> year;
			
			//checking if the year is within 1700 and 2400
			if(year > 2400 || year < 1700)
			{

				cout << "\nPlease enter year within given range (1700 - 2400).\nPress any key...\n";
				getch();
				system("cls");
				main();
				//clearing screen and calling main function again

			}
			
			//passing the valid date, month and year
			calender obj(date, month, year);
			i=obj.DayNumber(--date, month, year);
			cout << "\n" << ++date << "/" << month << "/" << year << " is ";
			i=i%7;
			obj.day(i);
		}

		//year range 1700-2400
		else if(i == 2)
		{

			month2:
			cout << "Enter month(mm): ";
			cin >> month;
			
			//checking if the month is valid
			if(month > 12 || month < 1)
			{

				cout << "\nPlease provide valid month.\nPress any key...\n";
				getch();
				system("cls");
				main();
				//clearing screen and calling main function again when the month is invalid


			}
			
			year2:
			cout << "Enter year(yyyy): ";
			cin >> year;


			//checking if the year is within 1700 and 2400
			if(year > 2400 || year < 1700)
			{

				cout << "\nPlease enter year within given range (1700 - 2400).\nPress any key...\n";
				getch();
				system("cls");
				main();
				//clearing screen and calling main function again

			}

			calender obj;
			obj.monthcal(month, year);

		}
		
		cout << "\nWould you like to try again (y/n) ";
		cin >> ch;
		
	}

	while(ch == 'y' || ch == 'Y');
	if (ch == 'n' || ch == 'N')
	{
		
		cout << "\n ================================================================================\n"
				<<"|\t\t\tThank You For Playing the Calendar \t\t\t|\n"
		    	<<"|\t\tThis quiz is made by students from SYCO WPU \t\t\t|\n"
		        <<"|\t\t\t\tCourse Outcomes: \t\t\t\t|\n"
   				<<"|\t\tTeamwork, Pressure handling and Trusting each other.\t\t|\n"
				<<"|===============================================================================|\n"
				<<"\t\t\t\t     Made by- \n"
				<<"\t\t\t\t  Mansi Mulik(16)\n"
				<<"\t\t\t\tHrushikesh Pandit(18)\n"
				<<"\t\t\t\t  Anish Panwala(20)\n"
				<<"\t\t\t\t  Amaan Shaikh(28)\n";
		cout << "\n---------------------------------------------------------------------------------\n";
		
	}
	return 0;
	
}
//EOF
