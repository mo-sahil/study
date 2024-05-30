import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class VotingSystem {
    private HashMap<String, User> users;
    private HashMap<String, Candidate> candidates;
    private static final String USERS_FILE = "users.txt";
    private static final String CANDIDATES_FILE = "candidates.txt";

    public VotingSystem() {
        users = new HashMap<>();
        candidates = new HashMap<>();
        loadUsers();
        loadCandidates();
    }

    public void signUp(String userId, String password) {
        if (users.containsKey(userId)) {
            System.out.println("User ID already exists. Please try logging in.");
        } else {
            User newUser = new User(userId, password);
            users.put(userId, newUser);
            saveUsers();
            System.out.println("Sign up successful! You can now log in.");
        }
    }

    public User login(String userId, String password) {
        User user = users.get(userId);
        if (user != null && user.getPassword().equals(password)) {
            System.out.println("Login successful!");
            return user;
        } else {
            System.out.println("Invalid user ID or password.");
            return null;
        }
    }

    public void addCandidate(String candidateName) {
        if (!candidates.containsKey(candidateName)) {
            candidates.put(candidateName, new Candidate(candidateName));
            saveCandidates();
        } else {
            System.out.println("Candidate already exists.");
        }
    }

    public void vote(User user, String candidateName) {
        if (user.hasVoted()) {
            System.out.println("You have already voted.");
        } else {
            Candidate candidate = candidates.get(candidateName);
            if (candidate != null) {
                candidate.addVote();
                user.setHasVoted(true);
                saveUsers();
                saveCandidates();
                System.out.println("Thank you for voting!");
            } else {
                System.out.println("Candidate not found.");
            }
        }
    }

    public void showResults() {
        System.out.println("Voting Results:");
        for (Map.Entry<String, Candidate> entry : candidates.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue().getVotes() + " votes");
        }
    }

    @SuppressWarnings("unchecked")
    private void loadUsers() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(USERS_FILE))) {
            users = (HashMap<String, User>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("User data file not found. Starting fresh.");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    @SuppressWarnings("unchecked")
    private void loadCandidates() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(CANDIDATES_FILE))) {
            candidates = (HashMap<String, Candidate>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("Candidates data file not found. Starting fresh.");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void saveUsers() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(USERS_FILE))) {
            oos.writeObject(users);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void saveCandidates() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(CANDIDATES_FILE))) {
            oos.writeObject(candidates);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
