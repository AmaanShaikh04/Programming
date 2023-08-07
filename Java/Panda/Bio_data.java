/* 
    File Name: Bio_data.java
    Code written by Amaan Shaikh
*/
import java.util.*;
public class Bio_data   //start of class Bio_data
{
    //start of main
    public static void main(String[] args)
    {
        //Declaring variables
        String name,fname,add,id,dob;
        long no;
        
        //Making Scanner object
        Scanner sc = new Scanner(System.in);
        
        //Accepting data
        System.out.println("Enter Following data:");
        
        System.out.println("Enter Name:");
            name = sc.nextLine();
        System.out.println("Enter Father's Name:");
            fname = sc.nextLine();
        System.out.println("Enter Date of Birth:");
            dob = sc.nextLine();
        System.out.println("Enter Address:");
            add = sc.nextLine();
        System.out.println("Enter Phone number:");
            no = sc.nextLong();
        System.out.println("Enter E-mail ID:");
            id = sc.next();
        
        //Printing data
        System.out.println("Desired Output:\n");
        
        System.out.println("Name\t\t:" + name);
        System.out.println("Father's Name\t:" + fname);
        System.out.println("Date of Birth\t:" + dob);
        System.out.println("Address\t\t:" + add);
        System.out.println("Phone No.\t:" + no);
        System.out.println("E-mail ID\t:" + id);
        
        //closing scanner object
        sc.close();
    }
    //end of main
}
//end of class
//EOF