/**
 * Expressions
 */
public class Expressions
{
    public static void main(String[] args)
    {
        double p,r=7,m=11,k=8;
        p=(r++%7)+(--m%5)+k*(++k-8);
        System.out.println(p);
    }
}