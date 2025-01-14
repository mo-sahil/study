import java.util.*;

public class Guess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rd = new Random();
        boolean guessed = false;

        for (int i = 0; i < 6; i++) {

            System.out.print("Guess your number(0-20): ");
            int guess = sc.nextInt();

            int random = rd.nextInt(21);

            if (random == guess) {
                guessed = true;
                System.out.println("Gotcha! you guessed it right");
                break;
            } else if (random > guess) {
                System.out.println("your guess is too low, computer: " + random);
            } else {
                System.out.println("your Guess is too high, computer: " + random);
            }
        }
        sc.close();

        if (!guessed) {
            System.out.println("ouch! you exhausted all your attempts");
        }
    }
}
