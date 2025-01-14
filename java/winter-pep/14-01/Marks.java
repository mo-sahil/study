public class Marks {
    public static void main(String[] args) {
        String str = "English 50 Science 76 Maths 90";
        String[] arr = str.split(" ");

        int sum = 0;

        for (int i = 1; i < arr.length; i += 2) {
            sum += Integer.parseInt(arr[i]);
        }

        System.out.println("Total Marks: " + sum + "\n Average Marks: " + sum / (arr.length / 2));
    }

}
