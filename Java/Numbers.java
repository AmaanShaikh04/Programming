import java.util.*;
class Numbers
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        int sum,prod,rem,a,b,diff;
        double quo;
        System.out.println("Enter 2 numbers");
        a=sc.nextInt();
        b=sc.nextInt();
        sum=a+b;
        prod=a*b;
        diff=a-b;
        quo=a/b;
        rem=a%b;
        System.out.println("Sum="+sum+"\nDifference="+diff+"\nProduct="+prod+"\nQuotient="+quo+"\nRemainder="+rem);
        sc.close();
    }
}