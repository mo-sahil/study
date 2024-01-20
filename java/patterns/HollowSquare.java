import java.util.*;

class HollowSquare{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==n-1 || j==0 || j==n-1)
                    System.out.print("* ");
                else {
                    System.out.print("  ");
                }
            }
            System.out.print("\n");
            
            scan.close();
        }
    }
}