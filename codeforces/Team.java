import java.util.Scanner;

public class Team {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int a, b , c, count = 0;
        for(int i = 0; i < n; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            if((a==1 && b==1) || (b==1 && c==1) || (c==1 && a==1)) count++;
        }

        System.out.println(count);
    }
}