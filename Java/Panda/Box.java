/*
 * Write a program to create a class "Box" having data members width, height, depth and boxno. Accept and Display data for two objects.

Note: 1. Create two constructors (default and parameterized) to initialize the data members. 

      2. Create accept() and display() methods in the class.
   */
import java.util.*;
public class Box
{
    static int width,height,depth,boxno;
    Box()
    {
        System.out.println("Inside default constructor\n");
    }
    Box(int a, int b, int c, int d)
    {
        System.out.println("Inside parameterised constructor\n");
        width=a;
        height=b;
        depth=c;
        boxno=d;
    }
    static void accept()
    {
        System.out.println("Enter Height, Width, Breadth and Box no of the Box");
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        int d=sc.nextInt();
        Box obj=new Box();
        Box obj1=new Box(a,b,c,d);
    }
    static void display()
    {
        System.out.println("Height:\t"+height);
        System.out.println("Depth:\t"+depth);
        System.out.println("Width:\t"+width);
        System.out.println("Box no:\t"+boxno);
    }
    public static void main(String args[])
    {
        for(int i=1;i<=2;i++)
        {
            accept();
            display();
        }
    }
}
