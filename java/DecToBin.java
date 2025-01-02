import java.util.Scanner;

public class DecToBin{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a number in decimal: ");
        int dec = scan.nextInt();
        scan.close();
        
        String bin = "";
        int temp = dec;

        while(temp > 0){
            int rem = temp%2;
            bin = rem + bin;
            temp /= 2;
        }

        System.out.println("Binary representation of " + dec + " is " + bin);
    }
}