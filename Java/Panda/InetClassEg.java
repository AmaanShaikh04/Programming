import java.net.*;
import java.util.Arrays;

public class InetClassEg
{
    public static void main(String[] arg) throws Exception
    {
        InetAddress lo = InetAddress.getLocalHost();
        InetAddress ip1 =  InetAddress.getByName("www.google.com");
        InetAddress[] ip2 = InetAddress.getAllByName("www.youtube.com");
        System.out.println("\nLocalhost:\t\t" +lo);
        System.out.println("IP:\t\t\t\t" +ip1);
        System.out.println("IP1:\t\t\t" + Arrays.toString(ip2));
        System.out.println("Address:\t\t" + Arrays.toString(ip1.getAddress()));
        System.out.println("Host Address:\t" +ip1.getHostAddress());
    }
}