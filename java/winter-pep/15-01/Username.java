import java.util.Scanner;

public class Username {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a username(8-30 caracter long, alphanumeric, _, Starts with alphabet: )");

        String name = sc.next();

        sc.close();

        String regEx = "^[a-zA-Z][a-zA-Z0-9_]{7,29}$";

        if (name.matches(regEx))
            System.out.println("Username Selected: " + name);
        else
            System.out.println("Username does not follow guidlines");
    }
}
