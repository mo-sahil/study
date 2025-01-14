public class Invitation {
    public static void main(String[] args) {
        String str = "Issac Newton,Neils Bohr & Rutherford,Robert Brown,Gorge Simon Ohm";
        String[] arr = str.split(",");

        for (int i = 0; i < arr.length; i++) {
            String[] tempArr = arr[i].split(" ");
            System.out.println("Dear Mr. " + tempArr[tempArr.length - 1] + "." + tempArr[0].charAt(0));
        }
    }
}
