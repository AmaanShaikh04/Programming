/*Write a program to implement Multilevel inheritance. (Use proper visibility modes to declare the data members).

          i. Create a class "Student" as base class having data members rollNo, Name.

         ii. Derive the class "Marks" from "Student" having data members sub1, sub2, sub3. 

         iii. Derive the class "Result" from "Marks" having data member percentage .

         - Define accept() method to accept the student  details.
         
         - Define the method finalResult() to calculate the percentage. 

         - Define display() method to show all the details of Student.
*/
import java.util.*;
public class Student
{
    protected int rollNo;
    protected String Name;
    public static void main(String args[])
    {
        Result obj = new Result();
        obj.accept();
        obj.finalResult();
        obj.display();
    }
}
class Marks extends Student
{
    protected double sub1,sub2,sub3;
}
class Result extends Marks
{
    private double percentage;
    public void accept()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roll No");
        rollNo=sc.nextInt();
        System.out.println("Enter Name");
        Name=sc.next();
        System.out.println("Enter Marks in Subject 1 out of 100");
        sub1=sc.nextDouble();
        System.out.println("Enter Marks in Subject 2 out of 100");
        sub2=sc.nextDouble();
        System.out.println("Enter Marks in Subject 3 out of 100");
        sub3=sc.nextDouble();
    }
    public void finalResult()
    {
        percentage=(sub1+sub2+sub3)/3;
    }
    public void display()
    {
        System.out.println("Student Details:\n");
        System.out.println("Roll no:\t"+rollNo);
        System.out.println("Name:\t\t"+Name);
        System.out.println("Subject 1:\t"+sub1);
        System.out.println("Subject 2:\t"+sub2);
        System.out.println("Subject 3:\t"+sub3);
        System.out.println("Percentage:\t"+percentage+"%");
    }
}