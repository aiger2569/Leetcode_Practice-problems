package Lab;

import java.util.Scanner;

public class prog3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");

        try {
            int userNumber = scanner.nextInt();
            if (isPalindrome(userNumber)) {
                System.out.println(userNumber + " is a palindrome.");
            } else {
                System.out.println(userNumber + " is not a palindrome.");
            }
        } catch (java.util.InputMismatchException e) {
            System.out.println("Invalid input. Please enter a valid number.");
        }
    }

    private static boolean isPalindrome(int number) {
        int originalNumber = number;
        int reversedNumber = 0;

        while (number > 0) {
            int digit = number % 10;
            reversedNumber = reversedNumber * 10 + digit;
            number /= 10;
        }

        return originalNumber == reversedNumber;
    }
}