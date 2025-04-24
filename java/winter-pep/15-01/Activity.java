class Employee {
    public int salary;
    public String job;
}

public class Activity {
    public static void main(String[] args) {
        Employee timi = new Employee();

        timi.salary = 5000;
        timi.job = "take attendence";

        System.out.println("Salary: " + timi.salary);
        System.out.println("Job: " + timi.job);
    }
}
