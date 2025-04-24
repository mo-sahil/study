import java.util.ArrayList;
import java.util.List;

class Student {
    private int studentID;
    private String name;
    private String major;
    private List<Course> coursesEnrolled;
    private double gpa;

    public Student(int studentID, String name, String major) {
        this.studentID = studentID;
        this.name = name;
        this.major = major;
        this.coursesEnrolled = new ArrayList<Course>();
        this.gpa = 0.0;
    }

    public void enrollCourse(Course course) {
        if (!coursesEnrolled.contains(course)) {
            coursesEnrolled.add(course);
            course.addStudent(this);
            System.out.println(name + " enrolled in " + course.getCourseName());
        } else {
            System.out.println(name + " is already enrolled in " + course.getCourseName());
        }
    }

    public void dropCourse(Course course) {
        if (coursesEnrolled.contains(course)) {
            coursesEnrolled.remove(course);
            course.removeStudent(this);
            System.out.println(name + " dropped " + course.getCourseName());
        } else {
            System.out.println(name + " is not enrolled in " + course.getCourseName());
        }
    }

    public void calculateGPA(List<Double> grades) {
        double totalPoints = 0.0;
        int totalCredits = 0;

        for (int i = 0; i < coursesEnrolled.size(); i++) {
            Course course = coursesEnrolled.get(i);
            totalPoints += grades.get(i) * course.getCredits();
            totalCredits += course.getCredits();
        }

        this.gpa = totalPoints / totalCredits;

        System.out.println("GPA of " + name + " is " + gpa);
    }
};

class Course {
    private String courseCode;
    private String courseName;
    private int credits;
    private Instructor instructor;
    private List<Student> enrolledStudents;

    public String getCourseName() {
        return courseName;
    }

    public int getCredits() {
        return credits;
    }

    public Course(String courseCode, String courseName, int credits, Instructor instructor) {
        this.courseCode = courseCode;
        this.courseName = courseName;
        this.credits = credits;
        this.instructor = instructor;
        this.enrolledStudents = new ArrayList<Student>();
    }

    public void addStudent(Student student) {
        if (!enrolledStudents.contains(student)) {
            enrolledStudents.add(student);
        }
    }

    public void removeStudent(Student student) {
        enrolledStudents.remove(student);
    }
};

class Instructor {
    private int instructorID;
    private String name;
    private String department;
    private List<Course> coursesTaught;

    public Instructor(int instructorID, String name, String department) {
        this.instructorID = instructorID;
        this.name = name;
        this.department = department;
        this.coursesTaught = new ArrayList<Course>();
    }

    public void assignCourse(Course course) {
        if (!coursesTaught.contains(course)) {
            coursesTaught.add(course);
            System.out.println(name + " assigned to teach " + course.getCourseName());
        }
    }
};

public class UMS {
    public static void main(String[] args) {
        System.out.println("University Management System");

        Instructor profSahil = new Instructor(1, "Dr. Sahil", "CSE");
        Instructor profMaz = new Instructor(2, "Dr. Maz", "ECE");

        Course cse101 = new Course("CSE101", "C Programming", 4, profSahil);
        Course int308 = new Course("INT308", "Python Programming", 3, profMaz);

        profSahil.assignCourse(cse101);
        profMaz.assignCourse(int308);

        Student sahil = new Student(1216811, "Sahil", "CSE");
        Student maz = new Student(12217054, "Maz", "ECE");

        sahil.enrollCourse(cse101);
        sahil.enrollCourse(int308);
        maz.enrollCourse(int308);

        sahil.calculateGPA(List.of(2.5, 3.7));
        maz.calculateGPA(List.of(2.7));
    }
}
