/*
   Filename: fibonacci.js
   Description: To display the fibonacci series.
   Author: Hrushikesh Pandit
*/
var t1 = 0, t2 = 0;
var n = 1;
document.write(+t1);
document.write("<br>"+t2);
while(n<=10)
{
  var t3 = t1 + t2;
  t1 = t2;
  t2 = t3;
  document.write("<br>"+t3);
  n++;
}
//EOF
