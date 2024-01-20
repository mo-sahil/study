import java.util.*;

class Fibonacci{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        System.out.print("enter limit: ");
        int n = scan.nextInt();
        scan.close();

        int a = 0, b = 1;
        while(a <= n){
            System.out.print(a + " ");
            int c = a + b;
            a = b;
            b = c;
        }

    }
}