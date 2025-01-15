// Design suitable data structures and implement Pass 1 of 2 for pseudo machines in JAVA
import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class ReadFile{
    public static void main(String[] args) {
        String filename = "input.txt";
        System.out.println("Current working directory: " + System.getProperty("user.dir"));

        try (BufferedReader br = new BufferedReader(new FileReader(filename))){
            String line;
            while ((line = br.readLine()) != null) {
                String[] tokens = line.split("\\s+");
                for (String token : tokens) {
                    System.out.println(token);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File "+ filename + " not found");
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file/n" + e);
            e.printStackTrace();
        }

    }
}