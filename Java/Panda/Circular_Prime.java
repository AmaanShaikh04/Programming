/*
* filename: Circular_Prime.java
* Author: Afsha Shaikh
* Roll no: 02
* */
import java.util.Scanner;

class Circular_Prime
{
    //function name: static boolean isPrime(int x)
    //description: to check if a number is prime or not
    static boolean isPrime(int x)
    {
        if (x <= 1)
            return false;   //as numbers less than or equal to 1 are not prime numbers
        if (x <= 3)
            return true;    //as number less than or equal to 3 and greater than 1 are prime numbers

        if (x % 2 == 0 || x % 3 == 0)
            return false;   //checks if x is divisible by 2 or 3

        for (int i=5;i<=x/2;i+=6)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    //end of static boolean isPrime(int x)
    //will return boolean value

    //function name: static boolean checkCircular(int c_num)
    //description: to check if the number is circular
    static boolean checkCircular(int c_num)
    {
        int ctr = 0, temp = c_num;
        while (temp>0) {
            ctr++;
            temp /= 10;
        }
        //number of digits of the number is store in ctr

        int num = c_num;
        while (isPrime(num)) //will check if num is prime by calling isPrime()
        {
            int r = num % 10;
            int d = num / 10;
            num = (int)((Math.pow(10, ctr - 1)) * r) + d;
            /*
                192
                r = 2
                10 ^ 2 = 100 * r
                200 + 19
                num = 219
            */
            System.out.println("Combination of digits: "+num);
            if (num == c_num)   //if all the possible combinations are prime, will return true
                return true;
        }

        return false;
    }
    //end of static boolean checkCircular(int c_num)
    //will return boolean value

    //start of main
    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a positive number:");
        int N = sc.nextInt();
        if (checkCircular(N))
            System.out.println(N+" is a Circular prime number");
        else
            System.out.println(N+" is not a Circular prime number");
    }
    //end of main
}
//end of Circular_Prime class