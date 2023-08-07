/*
 * Write a program to accept the string from user and perform following operations on string using built in methods of String class.

       i) Use one of the constructors from String class to create the String class object.

       ii) Find the length of the given string. (use length() method)

       iii) Concatenate two strings. (use concat() method)

       iv) Extract a character from given index. (use charAt() method)

       v) Compare two strings using equals() method.

       vi) Compare two strings using comapreTo() method.

       vii) Find the first and last occurrence of the given character in the string (use indexOf() and lastIndexOf() methods).

       viii) Extract the part of string from given string (Use substring() method).

        ix) Replace the old character with new character in the given string.(Use replace() method).

        x) Change the case of characters in the given string using toLowerCase() and toUpperCase() methods.
   */
import java.util.*;
public class String_Ex3_1
{
    public static void main(String args[])
    {
        String n = new String("Amaan Shaikh");
        Scanner sc = new Scanner(System.in);
        System.out.println("Experiment done by " + n);
        System.out.println("Enter 2 Strings");
        String s1 = sc.next();
        String s2 = sc.next();
        System.out.println("Length of s1 = " + s1.length() + "\nLength of s2 = " +s2.length());
        System.out.println("Concatenated string " + s1.concat(s2));
        System.out.println("Enter a position");
        int a = sc.nextInt();
        System.out.println("s1.ChatAt " +a+ " = " +s1.charAt(a)+ "\ns2.CharAt " +a+ " = " +s2.charAt(a));
        if(s1.equals(s2))
            System.out.println("Equal");
        else
            System.out.println("Not Equal");
        System.out.println("Compare: " +s1.compareTo(s2));
        System.out.println("Enter Character to search");
        char b = sc.next().charAt(0);
        System.out.println("First = " +s1.indexOf(b)+ "\nLast" +s1.lastIndexOf(b));
        System.out.println("First = " +s2.indexOf(b)+ "\nLast" +s2.lastIndexOf(b));
        System.out.println(s1.substring(1,5));
        System.out.println(s2.substring(3,7));
        System.out.println("Enter a character to replace");
        char c = sc.next().charAt(0);
        System.out.println(s1.replace(c,b));
        System.out.println(s2.replace(c,b));
        System.out.println("Lowercase = " +s1.toLowerCase());
        System.out.println("Uppercase = " +s2.toUpperCase());
    }
}
