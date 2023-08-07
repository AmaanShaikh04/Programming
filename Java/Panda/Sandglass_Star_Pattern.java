/*
 * filename: Sandglass_Star_Pattern.java
 * Author: Afsha Shaikh
 * Roll no: 02
 * */
import java.util.*;
public class Sandglass_Star_Pattern
{
    //start of main
    public static void main(String args[])
    {
        int x,i,j;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        x = sc.nextInt();
        char ch = '*';

        for(i=0; i<=x-1; i++)     //outer loop to print upper side
        {
            for (j=0; j<i; j++)
                System.out.print(" ");      //printing space

            for (j=i; j<=x-1; j++)
                System.out.print(ch+" ");   //printing character

            System.out.println();
        }
        for (i=x-1; i>=0; i--)     //inner loop to print lower side
        {
            //printing spaces
            for (j=0; j<i ;j++)
                System.out.print(" ");      //printing space

            for (j=i; j<=x-1; j++)
                System.out.print(ch+" ");   //printing character

            System.out.println();
        }
    }
    //end of main
}
//end of Sandglass_Star_Pattern class