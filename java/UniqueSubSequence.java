import java.util.HashSet;

public class UniqueSubSequence {
    public static void subSequences(String s, int idx, String ns, HashSet<String> hs){
        if(idx == s.length()){
            if(hs.contains(ns)) return;
            else{
                System.out.println(ns);
                hs.add(ns);
            }
            return;
        }

        subSequences(s, idx+1, ns+s.charAt(idx), hs);
        subSequences(s, idx+1, ns, hs);
    }

    public static void main(String[] args) {
        String s = "aba";
        HashSet<String> hs  = new HashSet<String>();
        subSequences(s, 0, "", hs);
    }
}
