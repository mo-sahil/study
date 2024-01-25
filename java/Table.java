import java.util.Scanner;

class Table {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        while(n < 1){
            System.out.println("Enter  number greater than zero");
            n = sc.nextInt();
        }
        sc.close();

        for(int i = 1; i <= 10; i++) {
            System.out.println(n + "*" + i + " = " + n*i);
        }
    }
}