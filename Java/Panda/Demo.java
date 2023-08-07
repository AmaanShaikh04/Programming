import java.util.*;
import java.lang.*;
public class Demo
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int a=sc.nextInt();
        double sq=Math.pow(a,2);
        double cb=Math.pow(a,3);
        double sqrt=Math.sqrt(a);
        double cbrt=Math.cbrt(a);
        System.out.println("Sqaure: "+sq);
        System.out.println("Cube: "+cb);
        System.out.println("Sqaure root: "+sqrt);
        System.out.println("Cube root: "+cbrt);
    }
}
