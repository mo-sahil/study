import java.util.Scanner;
import java.util.Stack;

public class BalancedParanthesis {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        sc.close();

        Stack<Character> st = new Stack<>();

        for (char c : str.toCharArray()) {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')' && !st.empty() && st.peek() == '(')
                st.pop();
            else if (c == ']' && !st.empty() && st.peek() == '[')
                st.pop();
            else if (c == '}' && !st.empty() && st.peek() == '{')
                st.pop();
            else {
                System.out.println("Invalid Character");
                return;
            }
        }

        if (st.empty())
            System.out.println("Parantheses are balanced");
        else
            System.out.println("Not balanced");
    }
}
