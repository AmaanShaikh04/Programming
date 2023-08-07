import java.net.*;

public class URL_Exp
{
        public static void main(String[] args)
        {
            try {
                URL link = new URL("https://en.wikipedia.org:8080/wiki/Blockchain");
                System.out.println("Host name:\t\t"+link.getHost());
                System.out.println("Protocol name:\t"+link.getProtocol());
                System.out.println("Port no:\t\t"+link.getPort());
                System.out.println("File name:\t\t"+link.getFile());
                System.out.println("Authority:\t\t"+link.getAuthority());
            }
            catch(Exception e)
            {
                System.out.println("Exception found: "+e);
            }
        }
}
