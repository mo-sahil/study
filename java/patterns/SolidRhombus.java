import java.util.*;

class SolidRhombus{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++)
                System.out.print(" ");
            
            for(int j=0; j<n; j++)
                System.out.print("*");
            System.out.print("\n");
        }

    }
}