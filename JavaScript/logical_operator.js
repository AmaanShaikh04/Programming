/*
  Filename: logical_operator.js
  Description: To use Logical operators in Conditional functions like if-else, else if.
  Author: Aditya Samudra
*/
var a=prompt("Enter a number")
var b=prompt("Enter a number")
var c=prompt("Enter a number")

if(a>b && a>c)
{
document.write("1st number is greatest");
}
else if (b>a && b>c)
{
document.write("2nd num is the greatest");
}
else 
{
document.write("3rd num is the greatest ");
}
//EOF
