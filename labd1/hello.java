package Lab;

import java.util.Scanner;

public class hello {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Roll No. : ");
        int rollNo = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter section: ");
        String section = scanner.nextLine();

        System.out.print("Enter branch: ");
        String branch = scanner.nextLine();

        System.out.println("Display Name: " + name);
        System.out.println("Display Roll No: " + rollNo);
        System.out.println("Display Section: " + section);
        System.out.println("Display Branch: " + branch);

        scanner.close();
    }
}