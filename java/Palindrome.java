import java.util.Scanner;

public class Palindrome{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number: ");
        long n = scan.nextLong();
        scan.close();
        
        long rev = 0;
        long temp = n;
        
        while(temp>0){
            long rem = temp%10;
            rev = rev*10 + rem;
            temp /= 10;
        }

        if(n == rev){
            System.out.println(n + " is palindrome.");
        } else {
            System.out.println(n + " is not palindrome.");
        }
    }
}