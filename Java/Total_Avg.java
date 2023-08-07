import java.util.*;
public class Total_Avg
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        double a,b,c,d,e,to,avg;
        System.out.println("Enter marks of 5 subjects");
        a=sc.nextDouble();
        b=sc.nextDouble();
        c=sc.nextDouble();
        d=sc.nextDouble();
        e=sc.nextDouble();
        to=a+b+c+d+e;
        avg=to/5;
        System.out.println("Total="+to+"\nAverage="+avg);
        sc.close();
    }
}