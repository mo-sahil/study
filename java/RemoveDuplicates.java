public class RemoveDuplicates {
    public static boolean[] map = new boolean[26];

    public static void removeDuplicates(String s, int idx, String ns){
        if(idx == s.length()){
            System.out.println("String " + s + " after removing duplicates -> " + ns);
            return;
        }

        char ch = s.charAt(idx);
        if(map[ch - 'a']){
            removeDuplicates(s, idx+1, ns);
        } else {
            ns += ch;
            map[ch - 'a'] = true;
            removeDuplicates(s, idx+1, ns);
        }
    }

    public static void main(String[] args) {
        String s = "abbccddasdf";

        removeDuplicates(s, 0, "");
    }
}
