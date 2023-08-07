/*
 *Write a program to accept the string from user and perform following operations on string using built in methods of StringBuffer class.

       i) Use one of the constructors from StringBuffer class to create the StringBuffer class object.

       ii) Find the length of the given string. (use length() method).

       iii) Use setLength() method to set the new length to the String.

       iv) Find the capacity of the string buffer.(Use capacity() method)

       v) Append new string at the end of old string. (use append() method)

       vi) Insert  a string at given index in the given string. (use insert() method)

       vii) Replace the substring in the given string with new string. (Use replace() method.

       viii) Reverse the given string using reverse() method.
 */
import java.util.*;
public class String_Ex3_2
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String");
        String str = sc.nextLine();
        StringBuffer sb= new StringBuffer(str);
        int l = sb.length();
        System.out.println("Length " +l);
        System.out.println("Enter the length of the string you desire");
        int a = sc.nextInt();
        if(a<sb.length())
            System.out.println("Not possible");
        else
        {
            sb.setLength(a);
            System.out.println("New length = " +sb.length());
        }
        System.out.println("Capacity: " +sb.capacity());
        System.out.println("Enter another string");
        sb.append(sc.next());
        System.out.println("New String after append = " +sb);
        sb.insert(4,'a');
        System.out.println("New String after insert = " +sb);
        sb.replace(2,5,"HI");
        System.out.println("New String after replace = " +sb);
        sb.reverse();
        System.out.println("New String after reverse = " +sb);
    }   
}
