import java.util.Scanner;

public class ReverseString{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scan.nextLine();
        scan.close();
        
        String rev = "";
        for(int i=0; i<s.length(); i++){
            rev = s.charAt(i) + rev;
        }

        System.out.println("Reverse of \"" + s + "\" is \"" + rev + "\"");
    }
}