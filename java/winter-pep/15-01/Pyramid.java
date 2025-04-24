import java.util.Scanner;

class Pyramid {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the height of the pyramid: ");
        int n = sc.nextInt();
        sc.close();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++)
                System.out.print(" ");
            for (int j = 1; j <= 2 * i - 1; j++)
                System.out.print("*");

            System.out.println("");
        }
    }
}