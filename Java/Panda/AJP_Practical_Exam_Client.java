/*
 * AJP practical exam question: Client side
 */

// importing all the required java packages
import java.net.*;
import java.io.*;

public class AJP_Practical_Exam_Client {
    public static void main(String[] args) throws IOException {
        Socket s = new Socket("localhost", 3031);           // using port number 3031

        //Creating DataInputStream and DataOutputStream objects
        DataInputStream d_in = new DataInputStream(s.getInputStream());
        DataOutputStream d_out = new DataOutputStream(s.getOutputStream());

        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));

        // setting string as null to accept values in them
        String str_client = "";
        String str_server = "";

        while(!str_server.equalsIgnoreCase("stop"))
        {
            str_client=buff.readLine();
            d_out.writeUTF(str_client);                     // writes a string to the underlying output stream and encodes

            d_out.flush();                                  // flushes the content of buffer

            str_server=d_in.readUTF();                      // reads in a string that has been encoded
            System.out.println("Server: "+str_server);

        }

        d_out.close();                                      // closing the output stream
        s.close();                                          // closing socket
    }
}
