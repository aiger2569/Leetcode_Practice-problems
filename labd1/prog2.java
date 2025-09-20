package lab;
import java.util.Scanner;
public class prog2
{
 public static void main(String[] args)
{
 Scanner scanner=new Scanner(System.in);
System.out.println("enter the weekday:");
int weekday=scanner.nextInt();
            scanner.close();
 switch(weekday){
case 1:System.out.print("SUN");break;
case 2:System.out.print("MON");break;
case 3:System.out.print("TUE");break;
case 4:System.out.print("WED");break;
case 5:System.out.print("THU");break;
case 6:System.out.print("FRI");break;
case 7:System.out.print("SAT");break;
default :System.out.print("iNvalid");break;


}
}}