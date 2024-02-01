import java.util.Scanner;

public class TowerOfHanoi {
    public static void TOH(int n, String src, String helper, String dest) {
        if(n == 1){
            System.out.println("Disk " + n + " Transferred: from " + src + " to " + dest);
            return;
        }
        TOH(n-1, src, dest, helper);

        System.out.println("Disk " + n + " Transferred: from " + src + " to " + dest);

        TOH(n-1, helper, src, dest);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        
        TOH(n, "Source", "Helper", "Destination");
    }
}
