import java.util.Scanner;

public class StringReverseUsingRecursion {
    public static String reverse(String s, int ind){
        if(ind < 0) return "";
        return s.charAt(ind) + reverse(s, ind-1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        sc.close();

        System.out.println("Reverse of " + s + " is = " + reverse(s, s.length()-1));
    }
}
