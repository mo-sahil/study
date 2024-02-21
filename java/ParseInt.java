import java.util.*;

class ParseInt{
    public static int decToBin(String n) {
        int dec = 0, i = n.length()-1, p = 0;
        while(i >= 0) dec += (n.charAt(i--)-'0')*Math.pow(2,p++);
        return dec;
    }
    public static void main(String args[]){
        String str = "100100", s = "111000";
        int n  = decToBin(str), m = decToBin(s);
        
        System.out.println(n^m);
    }
}