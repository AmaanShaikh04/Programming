/*
   Filename: switch_case.js
   Description: A code for using switch-case in javascript.
   Author: Aditya Samudra
*/
var a=prompt("Enter a number");
var b=prompt("Enter a number");
var result;

document.writeln("<br>1-> Addition");
document.writeln("<br>2-> Subtraction")
document.writeln("<br>3-> Multiplication");
document.writeln("<br>4-> Division");
var choice=prompt("Enter your choice");


switch (choice) {
   case "1" :
   n1=parseInt(a);
   n2=parseInt(b);
   result=n1+n2;
   break;
   
   case "2" :
   result =a-b;
   break;
   
   case "3" :a
   result =a*b;
   break;
   
   case "4" :
   result =a/b;
   break;
   
   default :
   doucument.writeln("<br>wrong choice");
   break;
 }

document.write("<br>Result="+result);
