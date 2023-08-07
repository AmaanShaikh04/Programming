import java.util.Scanner;
/*
 * Write a program to create 2 threads by implementing Runnable interface. One thread should find minimum number from given array and         other should find the maximum number from the given array.

     i. Set the priorities of the threads by calling setPriority() method. 

     ii. Set the priority of first thread as MIN_PRIORITY, and other thread with MAX_PRIORITY. 

     iii. Check the effect of setting priority.
   */
class Thread1 implements Runnable
{
    Scanner sc = new Scanner(System.in);
    int arr1[] = new int[5];
    Thread1()
    {
        for(int i=0;i<5;i++)
        {
            System.out.println("Enter Number"+(i+1)+" For Thread1");
            arr1[i]=sc.nextInt();
	}
    }
    public void run()
    {
	int min=arr1[0];
	for(int i=1;i<5;i++)
	{
	    if(min>arr1[i])
	    {
	        min=arr1[i];
	    }
	}
	System.out.println("Smallest Number:"+min);
    }
}
class Thread2 implements Runnable
{
    Scanner sc = new Scanner(System.in);
    int arr[] = new int[5];
    Thread2()
    {
	for(int i=0;i<5;i++)
	{
	    System.out.println("Enter Number"+(i+1)+" For Thread2");
	    arr[i]=sc.nextInt();
	}
    }
    public void run()
    {
	int max=arr[0];
	for(int i=1;i<5;i++)
	{
	    if(max<arr[i])
	    {
	        max=arr[i];
	    }
    	}
    	System.out.println("Largest Number:"+max);
    }
}
public class Runnable_Interface extends Thread
{
	public static void main(String args[])
	{
	    Thread1 obj1 = new Thread1();
	    Thread2 obj2 = new Thread2();
	    Thread t1 = new Thread(obj1);
	    Thread t2 = new Thread(obj2);
	    t1.setPriority(Thread.MIN_PRIORITY);
	    t2.setPriority(Thread.MAX_PRIORITY);
	    t1.start();
	    t2.start();
	}
}