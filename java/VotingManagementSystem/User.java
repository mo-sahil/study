import java.io.Serializable;

public class User implements Serializable {
    private String userId;
    private String password;
    private boolean hasVoted;

    public User(String userId, String password) {
        this.userId = userId;
        this.password = password;
        this.hasVoted = false;
    }

    public String getUserId() {
        return userId;
    }

    public String getPassword() {
        return password;
    }

    public boolean hasVoted() {
        return hasVoted;
    }

    public void setHasVoted(boolean hasVoted) {
        this.hasVoted = hasVoted;
    }
}
