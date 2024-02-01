import java.util.*;

class Occurence{
    public static int first = -1;
    public static int last = -1;

    public static void findOccurence(String s, int ind, char ch){
        if(ind == s.length()){
            System.out.println("First occurence: " + first);
            System.out.println("Last occurence: " + last);
            return;
        } else if(s.charAt(ind) ==  ch){
            if(first == -1) first = ind;
            else last = ind;
        }

        findOccurence(s, ind+1, ch);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();

        findOccurence(s, 0 , 'a');        
    }
}