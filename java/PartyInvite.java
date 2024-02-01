public class PartyInvite {
    public static int invites(int n){
        if(n <= 1) return 1;

        return invites(n-1) + (n-1) * invites(n-2);
    }

    public static void main(String[] args) {
        System.out.print(invites(4));
    }
}
