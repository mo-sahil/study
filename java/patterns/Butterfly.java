import java.util.Scanner;

class Butterfly{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                System.out.print("* ");
            }
            for(int j=0; j<2*n-2*(i+1); j++){
                System.out.print("  ");
            }
            for(int j=0; j<=i; j++){
                System.out.print("* ");
            }
            System.out.print("\n");
        }

        for(int i=n; i>0; i--){
            for(int j=0; j<i; j++){
                System.out.print("* ");
            }
            for(int j=0; j<=2*n-2*(i+1)+1; j++){
                System.out.print("  ");
            }
            for(int j=0; j<i; j++){
                System.out.print("* ");
            }
            System.out.print("\n");
        }

    }
}