/*
 * Write a program to create 2 threads by extending a Thread class.

     i. One thread should print the even numbers from 1 to 10 .

     ii. Other should print the odd numbers from 1 to 10.
   */
class Even extends Thread
{
    public void run()
    {
        System.out.println("Even Numbers");
        for(int i=0;i<=10;i+=2)
        {
            System.out.println(i);
        }
    }
}
class Odd extends Thread
{
    public void run()
    {
        System.out.println("Odd Numbers");
        for(int i=1;i<=10;i+=2)
        {
            System.out.println(i);
        }
    }
}
public class Multi_Thread
{
    public static void main(String args[])
    {
        Even obj1=new Even();
        Odd obj=new Odd();
        obj1.start();
        obj.start();
    }
}