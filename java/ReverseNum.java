import java.util.Scanner;

public class ReverseNum{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number to reverse: ");
        int n = scan.nextInt();
        scan.close();
        
        int rev = 0;
        int temp = n;

        while(temp > 0){
            int rem = temp%10;
            rev = rev*10 + rem;
            temp /= 10;
        }

        System.out.println("Reverse of " + n + " is " + rev);
    }
}