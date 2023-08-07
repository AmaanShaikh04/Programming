import java.net.*;
import java.util.*;

public class URL_Exp_1
{
    public static void main(String[] args) throws Exception
    {
        URLConnection website_c = new URL("https://www.kali.org/tools/burpsuite/").openConnection();

        /*
         *   .getContentLengthLong()
         *   - Returns the value of the content-length header field as a long.
         */
        System.out.println("Length of content \t-> "+website_c.getContentLengthLong());

        /*
         *   .getContentType()
         *   - Returns the value of the content-type header field.
         */
        System.out.println("Type of content \t-> "+website_c.getContentType());

        /*
         *   .getDate()
         *   - Returns the value of the date header field.
         */
        if (website_c.getDate() == 0)
            System.out.println("No date given");
        else {
            System.out.println("Date \t\t\t\t-> " + new Date(website_c.getDate()));
        }

        /*
         *   .getExpiration()
         *   - Returns the value of the expires header field.
         */
        if(website_c.getExpiration() == 0)
            System.out.println("Unknown Expiration");
        else
            System.out.println("Expiration \t\t\t-> "+new Date(website_c.getExpiration()));
    }
}