public class MoveChars {
    public static void moveChars(String s, int idx, String ns, int count){
        if ( idx == s.length()){
            for(int i=0; i<count; i++){
                ns += 'x';
            }
            System.out.println("String " + s + " after moving all x's to the right " + ns);
            return;
        }

        if(s.charAt(idx) == 'x'){
            count++;
        } else {
            ns += s.charAt(idx);
        }
        moveChars(s, idx+1, ns, count);
    }

    public static void main(String[] args) {
        String s = "axbxxcdxx";
        moveChars(s, 0, "", 0);
    }
}
