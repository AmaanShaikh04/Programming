/*
 *	File name:	Microproject_Calendar.cpp
 *	Description: Program based on a calendar.
 *	Authors: Amaan Shaikh, Mansi Mulik, Hrushikesh Pandit and Anish Panwala
 *	(c) 2020 A.M.H.A.
 */
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class calender
{
	private:
		int first_day,numdays,year,month,day;
	public:
		calender();
   
	bool leap(int );
	int dayName(int ) ;            
	void show_cal(int );  
	void space(int );
	void print_month(int);
	void printDays();
};
calender::calender(){
 numdays=0;
 year=1;
 month=1;
 day=1;
 
 
}

void calender::printDays(){
 print_month(month);
 cout<<endl;
 cout<<"___________________________________________________________________\n";
 cout<<"M\tT\tW\tT\tF\tS\tS\n";
 cout<<"___________________________________________________________________\n\n";
}

void calender::space(int w){
 for(int i=1; i<=w-1;i++){
  cout<<"\t";
 }
}
int calender::dayName(int a){
 
 
 int x1,x2,x3;
int first_day;
x1=(a-1)/4;
x2=(a-1)/100;
x3=(a-1)/400;
first_day=(a+x1-x2+x3)%7;
if(first_day==0)
first_day=7;
return first_day;
}
void calender::show_cal(int year2){

 int daycount,lp,z;
int week_day;
z=year2;

week_day= dayName(z);
daycount=week_day;

 while(month<=12){
  printDays();
  if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
   
  
   
   space(daycount);
   
   for(int x=1; x<=31; x++){
    cout<<day<<"\t";
   day++;
   daycount++;
   if(daycount>7){
    cout<<"\n\n";
    daycount=1;
   }
    
   }
   
   day=1;
   month++;
   cout<<endl;
  }
  else if(month==2){
  
   space(daycount);
  lp= leap(z);
   if (lp){
    for(int x=1; x<=29; x++){
    cout<<day<<"\t";
   day++;
   daycount++;
   if(daycount>7){
    cout<<"\n\n";
    daycount=1;
   }
   
   }
   day=1;
   month++;
   cout<<endl; 
    
   }
       else {
        for(int x=1; x<=28; x++){
    cout<<day<<"\t";
   day++;
   daycount++;
   if(daycount>7){
    cout<<"\n\n";
    daycount=1;
   }
    
   }
   day=1;
   month++;
   cout<<endl;
    }
  }                 // end of the second "if" i.e month==2
  
  else if(month==4||month==6||month==9||month==11){
 
   
   space(daycount);
   for(int x=1; x<=30; x++){
    cout<<day<<"\t";
   day++;
   daycount++;
   if(daycount>7){
    cout<<"\n";
    daycount=1;
   }
    
   }
   day=1;
   month++;
   cout<<endl;
   
  }                // End of Third If i,e month==4...
  
  
 }     // End Of While Loop....
 month=1;
 
}

bool calender::leap(int ye)

{  

    return   ((ye%4==0) && (ye%100 !=0))||(ye%400==0)  ;     
}
void   calender::print_month(int m){
 switch(m){
  case 1:
   cout<<"\n\t\t\tJanuary";
   break;
   case 2:
   cout<<"\n\t\t\tFebruary";
   break;
   case 3:
   cout<<"\n\t\t\tMarch";
   break;
   case 4:
   cout<<"\n\t\t\tApril";
   break;
   case 5:
   cout<<"\n\t\t\tMay";
   break;
   case 6:
   cout<<"\n\t\t\tJune";
   break;
   case 7:
   cout<<"\n\t\t\tJuly";
   break;
   case 8:
   cout<<"\n\t\t\tAugust";
   break;
   case 9:
   cout<<"\n\t\t\tSeptember";
   break;
   case 10:
   cout<<"\n\t\t\tOctober";
   break;
   case 11:
   cout<<"\n\t\t\tNovember";
   break;
   case 12:
   cout<<"\n\t\t\tDecember";
   break;
   default:
    cout<<"Invalid Input";
 }
}

calender obj;
main(){
 op:
 int year;
 char option;
 cout<< "Enter Year That You Want To Calender For: ";
 cin>>year;
 obj.show_cal(year);
 
 cout<<"\n\nDo You Want To Calender Again? \nPress Y if yes, N if no";
 option=getch();
 if(option=='Y'||option=='y'){
  system("cls");
  main();
 }
 else 
 exit(1);
// goto op;
 
}
//EOF
