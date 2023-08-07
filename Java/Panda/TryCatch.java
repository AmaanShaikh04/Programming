import java.util.Scanner;
/* 
 * Write any program to demonstrate the use of try, catch and finally blocks.
   */
public class TryCatch
{
    public static void main(String[] args)
    {
        int a, b, div;
        String obj=null;
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter num1 and num2:");
        a = scan.nextInt();
        b = scan.nextInt();
        try 
        {
            div = a / b;
            System.out.println(a+"/"+b+" = "+div);
            System.out.println(obj.length());
        }catch (ArithmeticException e) 
        {
            System.out.println("Cannot divide by zero.\n"+ e);
        }catch (NullPointerException e) 
        {
            System.out.println("No memory allocated to object of class String.\n"+e);
        }
    }
}