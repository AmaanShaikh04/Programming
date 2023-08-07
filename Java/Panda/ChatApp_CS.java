import java.net.*;
import java.io.*;

public class ChatApp_CS
{
    public static void main(String[] args) throws Exception
    {
        Socket s = new Socket("localhost", 3021);

        DataInputStream d_input = new DataInputStream(s.getInputStream());
        DataOutputStream d_output = new DataOutputStream(s.getOutputStream());

        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        String str_cl="";
        String str_ss="";

        while(!str_ss.equals("stop"))
        {
            str_cl=buff.readLine();
            d_output.writeUTF(str_cl);

            d_output.flush();

            str_ss=d_input.readUTF();
            System.out.println("Server: "+str_ss);

        }

        d_output.close();
        s.close();
    }
}
