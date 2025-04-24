import java.util.*;

public class TODO {
    public static void showTask(ArrayList<String> list) {
        if (list.isEmpty()) {
            System.out.println("No Task Available");
        } else {
            int i = 1;
            for (String task : list) {
                System.out.println(i++ + ": " + task);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<String> list = new ArrayList<>();

        while (true) {
            System.out.println("\n\nTODO List");
            System.out.println("Press 1 to enter a new task");
            System.out.println("Press 2 to delete a task");
            System.out.println("Press 3 to show all tasks");
            System.out.println("Press any other number to exit");
            int n = sc.nextInt();
            sc.nextLine();
            switch (n) {
                case 1:
                    System.out.println("Enter the task to add: ");
                    String task = sc.nextLine();
                    list.add(task);
                    System.out.println("Task added successfully");
                    break;
                case 2:
                    System.out.println("Enter respective task number to delete:");
                    showTask(list);
                    int idx = sc.nextInt();
                    if (idx >= 1 && idx <= list.size())
                        list.remove(idx - 1);
                    break;
                case 3:
                    showTask(list);
                    break;
                default:
                    System.out.println("Exiting");
                    sc.close();
                    return;
            }
        }
    }
}
