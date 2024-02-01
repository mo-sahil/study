import java.util.Scanner;

class Star{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        while(n < 1){
            System.out.println("Enter  number greater than zero");
            n = sc.nextInt();
        }
        sc.close();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}