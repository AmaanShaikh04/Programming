//To find minimum element
import java.util.*;
public class Arr
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows");
        int n=sc.nextInt();
        System.out.println("Enter the number of column");
        int c=sc.nextInt();
        int arr[][]=new int[n][c];
        System.out.println("Enter the elements");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c;j++)
                arr[i][j]=sc.nextInt();
        }
        System.out.println("Enter a number to be added");
        int x=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c;j++)
                arr[i][j]+=x;
        }
        System.out.println("The modified array is:");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c;j++)
                System.out.print(arr[i][j]+"\t");
            System.out.println("\n");
        }
    }
}
