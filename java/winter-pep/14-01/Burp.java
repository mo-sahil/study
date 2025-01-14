import java.util.Scanner;

public class Burp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Burp Size: ");
        int burp = sc.nextInt();
        sc.close();

        if (burp < 4) {
            System.out.println("Please enter a burp size of atleast 4");
        } else {
            System.out.print("Bu");
            for (int i = 0; i < burp - 3; i++)
                System.out.print('r');
            System.out.print("p\n");
        }
    }
}
