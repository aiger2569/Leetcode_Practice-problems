package lab;
import java.util.Scanner;
public class prog1

{
 public static void main(String[] args)
{
 Scanner scanner=new Scanner(System.in);
 System.out.println("this program is for grade evaluation:");
 
 System.out.println("this is the marks obtained by the student in  the subject:");
  int mark=scanner.nextInt();
  scanner.close();
char grade;
if(mark>=90){
grade='O';}
else if(80<=mark){
grade='E';
}
else if(70<=mark){
grade='A';
}else if(60<=mark){
grade='B';
}else if(50<=mark){
grade='C';
}else if(40<=mark){
grade='D';
}
else {
grade='F';
}
System.out.print("GRADE: "+grade);
}
}