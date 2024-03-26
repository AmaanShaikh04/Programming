// importing all the required java packages
import java.net.*;
import java.io.*;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(3031);       //using the same port number as the one given to client to establish connection
        Socket s = ss.accept();

        //Creating DataInputStream and DataOutputStream objects
        DataInputStream d_in = new DataInputStream(s.getInputStream());
        DataOutputStream d_out = new DataOutputStream(s.getOutputStream());

        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));

        // setting string as null to accept values in them
        String str_client = "";
        String str_server = "";

        while(!str_client.equalsIgnoreCase("stop"))
        {
            str_client=d_in.readUTF();          // reads in a string that has been encoded
            System.out.println("Client: "+str_client);

            str_server=buff.readLine();         // accepting message from server side
            d_out.writeUTF(str_server);         // writes a string to the underlying output stream and encodes

            d_out.flush();                      // flushes the content of buffer
        }

        d_in.close();                           // closing the input stream
        s.close();                              // closing socket
        ss.close();                             // closing server socket
    }
}