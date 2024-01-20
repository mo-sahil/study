import java.util.Scanner;

class Square{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int side = scan.nextInt();

        for(int i=0; i<side; i++){
            for(int j=0; j<side; j++){
                System.out.print("* ");
            }
            System.out.print("\n");
        }

        scan.close();
    }
}