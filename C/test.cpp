#include<stdio.h>
#include<math.h>
//start of the function


/*
conversion functions
Km to miles
inches to foot
cms to inches
pounds to kgs
inches to meter
*/
//function to convert [KM to Miles];
int KMTM(int a)
{
 printf("valid");
}
//function to convert inches to foot
int ITF(int a)
{
 printf("valid");
}
//function to convert Cm to inches
int CMTI(int a)
{
 printf("valid");
}
//function to convert Pounds to kg
int PTK(int a)
{
 printf("valid");
}
//function to convert inches to meters;
int ITM(int a)
{
 printf("valid");
}
 
//function to call respective operation functions;
int function(int a)
{
 switch(a)
 {
  case 1: 
  {
   printf("You have selected KM to Miles");
   KMTM(a);
   break;
  }
  
  case 2: 
  {
   printf("You have selected KM to Miles");
   ITF(a);
   break;
  }
  
  case 3: 
  {
   printf("You have selected KM to Miles");
   CMTI(a);
   break;
  }
  
  case 4: 
  {
   printf("You have selected KM to Miles");
   PTK(a);
   break;
  }
  
  case 5: 
  {
   printf("You have selected KM to Miles");
   ITM(a);
   break;
  }
  default:
  {
   printf("invalid input,please re-enter : "); 
  } 
 }
}
//start of the main function;
int main()
{
 int op;                           //variable for operation = op;
 printf("\t1.KM to Miles. \n\t2.Inches to foot\n\t3.CM to Inches\n\t4.Pounds to Kg\n\t5.Inches to meters\nEnter the operation to be performed : ");
 scanf("%d",&op);
 
 function(op);
 
 return 0;
}
