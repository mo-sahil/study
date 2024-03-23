import java.util.Scanner;

public class WayTooLongWords {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        String str = new String("");
        for(int i = 0; i<n; i++) {
            str = sc.next();
            if(str.length() <= 10) System.out.println(str);
            else System.out.println(str.charAt(0) + ("" + (str.length()-2)) + str.charAt(str.length()-1));
        }
    }
}