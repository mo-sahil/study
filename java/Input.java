import java.util.Scanner;

class Input{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter Username");
        myObj.close();
        
        String userName = myObj.nextLine();

        System.out.println("Enter age");
        int age = myObj.nextInt();
        System.out.println("Username is " + userName + " and age is " + age);
    }
}