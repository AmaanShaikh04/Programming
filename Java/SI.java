import java.util.Scanner;
public class SI
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        double p,r,a,t,si;
        System.out.println("Enter Pricipal Amount, Rate of Interest and Time period(in hours)");
        p=sc.nextDouble();
        r=sc.nextDouble();
        t=sc.nextDouble();
        si=(p*r*t)/100;
        a=si+p;
        System.out.println("Simple Interest on the principle="+si+"\nAmount="+a);
        sc.close();
    }
}