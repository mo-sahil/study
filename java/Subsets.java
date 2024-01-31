import java.util.ArrayList;

public class Subsets {
    public static void subSets(int n, ArrayList <Integer> subsets) {
        if(n==0){
            for(int i=subsets.size() - 1; i >= 0; i--){
                System.out.print(subsets.get(i) + " ");
            }
            System.out.println();
            return;
        }

        subsets.add(n);
        subSets(n-1, subsets);

        subsets.remove(subsets.size() - 1);
        subSets(n-1, subsets);
    }

    public static void main(String[] args) {
        ArrayList<Integer> subsets = new ArrayList<> ();

        subSets(4, subsets);
    }
}
