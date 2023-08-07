/*
 * Write a program to create a class "Student" having data members name, rollno, age and percentage. Accept and Display data for one object.

Note: 1. Create constructor (default/ parameterized) to initialize the data members. 

      2. Create accept() and display() methods in the class.
   */
import java.util.*;
public class Student1
{
    static String name;
    static int rollno,age;
    static double per;
    Student1(String a, int b, int c, double d)
    {
        System.out.println("Inside Parameterised constructor\n");
        name=a;
        rollno=b;
        age=c;
        per=d;
    }
    static void accept()
    {
        System.out.println("Enter name, roll no, age and percentage of student");
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        int b=sc.nextInt();
        int c=sc.nextInt();
        double d=sc.nextDouble();
        Student1 obj1=new Student1(a,b,c,d);
    }
    static void display()
    {
        System.out.println("Name:\t\t"+name);
        System.out.println("Roll No:\t"+rollno);
        System.out.println("Age:\t\t"+age);
        System.out.println("Percentage:\t"+per);
    }
    public static void main(String args[])
    {
        accept();
        display();
    }
}
