import java.util.Scanner;

public class HailstoneSequence {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a positive number: ");
        int n = sc.nextInt();
        sc.close();

        while (n != 1) {
            System.out.print(n + " ");
            if (n % 2 != 0)
                n = n * 3 + 1;
            else
                n /= 2;
        }

    }
}
