import java.util.Scanner;

class PoundToKG {
    public static void main(String[] var0) {
        Scanner var1 = new Scanner(System.in);
        System.out.print("Enter weight in pounds: ");
        double var2 = var1.nextDouble();
        double var4 = var2 / 2.205;
        System.out.println("Weight in KG: " + var4);
        var1.close();
    }
}