import java.util.*;

class GCD{
    public static int gcd(int x, int y){
        int min = Math.min(x, y);
        int gcd = 0;
        for(int i=1; i<min; i++){
            if(x%i == 0 && y%i == 0)
                gcd = i;
        }
        return gcd;
    }

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int y = scan.nextInt();
        scan.close();

        int gcd = gcd(x, y);
        System.out.println("gcd: " + gcd);
    }
}