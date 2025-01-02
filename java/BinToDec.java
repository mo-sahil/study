import java.util.Scanner;

public class BinToDec{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a binary no: ");
        int n = scan.nextInt();
        scan.close();
        
        int temp = n;
        double dec = 0;
        int i = 0;

        while(temp > 0){
            int rem = temp%10;
            dec += rem*Math.pow(2, i++);
            temp /= 10;
        }

        System.out.println("Decimal representation of binary number \"" + n + "\" is \"" + (int)dec + "\"");
    }
}