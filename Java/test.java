import java.util.*;
public class test
{

	public static void fact(int a)
	{
		if (a!=0)
		{
			System.out.println(a);
			a-=1;
			fact(a);
		}
	}
	public static void main(String args[])
	{
		fact(10);
		System.out.println("End of program");
	}
}