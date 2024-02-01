import java.util.Scanner;

class Fib {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();

        int count = 0, a = 0, b = 1;
        
        while(count++<n){
            System.out.print(b + " ");
            int temp = b;
            b += a;
            a = temp;
        }
    }
}
