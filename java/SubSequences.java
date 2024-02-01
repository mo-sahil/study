public class SubSequences {
    public static void subSequences(String s, int idx, String ns){
        if(idx == s.length()){
            System.out.println(ns);
            return;
        }

        subSequences(s, idx+1, ns+s.charAt(idx));
        subSequences(s, idx+1, ns);
    }

    public static void main(String[] args) {
        String s = "abc";
        subSequences(s, 0, "");
    }
}
