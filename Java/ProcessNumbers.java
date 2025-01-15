import java.util.ArrayList;
import java.util.Scanner;
public class ProcessNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<>();
        while (true) {
            int number = scanner.nextInt();
            if (number < 0) {
                break;
            }
            numbers.add(number);
        }
        for (int num : numbers) {
            System.out.println(processNumber(num));
        }
        scanner.close();
    }
    private static int processNumber(int number) {
        boolean isInternal = number < 53;
        boolean isExternal = number % 10 == 3;
        if (isInternal && isExternal) {
            return -3;
        } else if (isInternal) {
            return -7;
        } else if (isExternal) {
            return -9;
        } else {
            return number;
        }
    }
}
