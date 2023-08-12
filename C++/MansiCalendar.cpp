/*
 *	File name:	Microproject_Calendar.cpp
 *	Description: Program based on a calendar.
 *	Authors: Amaan Shaikh, Mansi Mulik, Hrushikesh Pandit and Anish Panwala
 *	(c) 2020 A.M.H.A.
 */

//including header files

#include <iostream>
//to use C functionalities
#include <cstdio>
using namespace std;
using std::printf;

class C
{
	public:
	void cal()
	{
	int yy, dd, mm, nleap, count, scount, i=1;
	long int dp;
	
	//to run the loop until year is less that 1 
	do
	{
		cout << "\nEnter the year: ";
		cin >> yy;
	}while(yy < 1);
	
	//to run the loop until month is between 1 and 12
	do
	{
		cout << "\nEnter the month: ";
		cin >> mm;
	}while(mm < 1 || mm > 12);
	
	//assigning number of days in months
	if(mm == 4 || mm == 6 || mm == 9 || mm == 11)
	  {
	  	dd = 30;
	  }
	  
		if(yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0)
		{
	  		if(mm == 2)
	  	 	{
	  	   		dd = 29;	
	  	 	}
	  	}
		else
	  	{
	  		if(mm == 2)
	  	 	{
		  	   	dd = 28;	
	  	 	}
	  	}
	  
	  if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
	    dd = 31;
	  
	  nleap = (yy - 1) / 4 -(yy - 1) / 100 +(yy - 1) / 400;
	  dp = (yy - 1) * 365l + nleap;
	  
	   switch(mm)
	   {
	   	case 12:dp+=30;
		case 11:dp+=31;
		case 10:dp+=30;
		case  9:dp+=31;
		case  8:dp+=31;
		case  7:dp+=30;
		case  6:dp+=31;
		case  5:dp+=30;
		case  4:dp+=31;
		case  3:dp+=28;
		case  2:dp+=31;
		case  1:dp+=1;   
	   }
	   
	   cout << "\nmon tue wed thu fri sat sun";
	    switch(dp % 7)
	    {
	    	case 1: count=0;
	    	        break;
	    	case 2: count=4;
	    	        break;
	    	case 3: count=8;
	    	        break;
	    	case 4: count=12;
	    	        break;
	    	case 5: count=16;
	    	        break;
	    	case 6: count=20;
	    	        break;
	    	default : count=24;   //case 0: printf(" Sunday"); 
	    }
	    cout << "\n";
	    scount = count;
	   while(scount>0)
	   {
	   	cout << " ";
	   	--scount;
	   }
	   while(dd >= i)
	   {
	    if(count % 28 == 0)
	    	cout << "\n";
	   	printf("%3d ",i);
	   	i++;
	   	count+=4;
	   } 
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
};
//start of main method

int main()
{
	C obj;
	obj.cal();
}

