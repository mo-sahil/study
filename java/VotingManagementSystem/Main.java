import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        VotingSystem votingSystem = new VotingSystem();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("Welcome to the Voting Management System");
            System.out.println("1. Login");
            System.out.println("2. Sign Up");
            System.out.println("3. Add Candidate");
            System.out.println("4. Show Results");
            System.out.println("5. Exit");
            System.out.print("Please choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine();  // Consume newline

            switch (choice) {
                case 1:
                    System.out.print("Enter User ID: ");
                    String userId = scanner.nextLine();
                    System.out.print("Enter Password: ");
                    String password = scanner.nextLine();
                    User user = votingSystem.login(userId, password);
                    if (user != null) {
                        System.out.print("Enter candidate name: ");
                        String candidateName = scanner.nextLine();
                        votingSystem.vote(user, candidateName);
                    }
                    System.out.println("\n\n");
                    break;

                case 2:
                    System.out.print("Enter User ID: ");
                    userId = scanner.nextLine();
                    System.out.print("Enter Password: ");
                    password = scanner.nextLine();
                    votingSystem.signUp(userId, password);
                    System.out.println("\n\n");
                    break;

                case 3:
                    System.out.print("Enter candidate name: ");
                    String candidateName = scanner.nextLine();
                    votingSystem.addCandidate(candidateName);
                    System.out.println("\n\n");
                    break;

                case 4:
                    votingSystem.showResults();
                    System.out.println("\n\n");
                    break;

                case 5:
                    running = false;
                    System.out.println("Exiting the system. Goodbye!");
                    System.out.println("\n\n");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    System.out.println("\n\n");
            }
        }

        scanner.close();
    }
}
