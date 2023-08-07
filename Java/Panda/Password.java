import java.util.Scanner;
/*
 * Write a program to check whether the password is valid or not for given user name.

      Create your own exception class for checking the validity of password.
   */
class Pass_Check extends Exception
{
    Pass_Check()
    {
        super("Password is not valid.");
    }
}
public class Password
{
    public static void main(String[] args) throws Pass_Check
    {
        Scanner scan = new Scanner(System.in);
        String pass = new String("Pass123");
        String inpPass = new String();

        System.out.println("Enter password for username Amaan Shaikh -> ");
        inpPass = scan.next();
        if (inpPass.equals(pass))
        {
            System.out.println("You have successfully logged in!");
        }
        else
        {
            throw new Pass_Check();
        }
    }
}