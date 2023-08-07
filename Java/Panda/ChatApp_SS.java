import java.net.*;
import java.io.*;

public class ChatApp_SS
{
    public static void main(String[] args) throws Exception
    {
        ServerSocket ss = new ServerSocket(3021);
        Socket s = ss.accept();

        DataInputStream d_input = new DataInputStream(s.getInputStream());
        DataOutputStream d_output = new DataOutputStream(s.getOutputStream());

        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        String str_cl="";
        String str_ss="";

        while(!str_cl.equals("stop"))
        {
            str_cl=d_input.readUTF();
            System.out.println("Client: "+str_cl);

            str_ss=buff.readLine();
            d_output.writeUTF(str_ss);

            d_output.flush();
        }

        d_input.close();
        s.close();
        ss.close();
    }
}
