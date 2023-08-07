import java.net.InetAddress;
import java.net.UnknownHostException;

public class FindIP {
    public static void main(String[] args) throws UnknownHostException {
        InetAddress lclhst = InetAddress.getLocalHost();

        System.out.println(lclhst);
    }
}