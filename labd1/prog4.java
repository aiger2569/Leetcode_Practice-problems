package lab;
import java.util.Scanner;
public class prog4{
public static void main(String args[]){
 Scanner scanner=new Scanner(System.in);
System.out.println("Enter the first name");
String fname= scanner.nextLine();
System.out.println("Enter the SECOND name");
String Sname= scanner.nextLine();
scanner.close();
System.out.println("the output is:");
System.out.print(Sname+" "+fname);


}}