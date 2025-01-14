import java.util.Scanner;

class GrossPay {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Basic Pay: ");
        int basic = sc.nextInt();
        sc.close();

        if (basic >= 5000) {
            System.out.println("Gross Pay is : " + basic * 1.26);
        } else {
            System.out.println("Gross Pay is : " + basic * 1.34);
        }
    }
}